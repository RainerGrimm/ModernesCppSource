using namespace std::execution;

sender auto async_inclusive_scan(scheduler auto sch,                          // 2
                                 std::span<const double> input,               // 1
                                 std::span<double> output,                    // 1
                                 double init,                                 // 1
                                 std::size_t tile_count)                      // 3
{
  std::size_t const tile_size = (input.size() + tile_count - 1) / tile_count;

  std::vector<double> partials(tile_count + 1);                               // 4
  partials[0] = init;                                                         // 4

  return just(std::move(partials))                                            // 5
       | continues_on(sch)
       | bulk(tile_count,                                                     // 6
           [ = ](std::size_t i, std::vector<double>& partials) {              // 7
             auto start = i * tile_size;                                      // 8
             auto end   = std::min(input.size(), (i + 1) * tile_size);        // 8
             partials[i + 1] = *--std::inclusive_scan(begin(input) + start,   // 9
                                                      begin(input) + end,     // 9
                                                      begin(output) + start); // 9
           })                                                                 // 10
       | then(                                                                // 11
           [](std::vector<double>&& partials) {
             std::inclusive_scan(begin(partials), end(partials),              // 12
                                 begin(partials));                            // 12
             return std::move(partials);                                      // 13
           })
       | bulk(tile_count,                                                     // 14
           [ = ](std::size_t i, std::vector<double>& partials) {              // 14
             auto start = i * tile_size;                                      // 14
             auto end   = std::min(input.size(), (i + 1) * tile_size);        // 14
             std::for_each(begin(output) + start, begin(output) + end,        // 14
               [&] (double& e) { e = partials[i] + e; }                       // 14
             );
           })
       | then(                                                                // 15
           [ = ](std::vector<double>&& partials) {                            // 15
             return output;                                                   // 15
           });                                                                // 15
}