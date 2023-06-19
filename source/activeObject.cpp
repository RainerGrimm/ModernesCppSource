#include <algorithm>
#include <deque>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <numeric>
#include <random>
#include <thread>
#include <utility>
#include <vector>

using std::async;
using std::boolalpha;
using std::cout;
using std::deque;
using std::distance;
using std::for_each;
using std::find_if;
using std::future;
using std::lock_guard;
using std::make_move_iterator;
using std::make_pair;
using std::move;
using std::mt19937;
using std::mutex;
using std::packaged_task;
using std::pair;
using std::random_device;
using std::sort;
using std::jthread;
using std::uniform_int_distribution;
using std::vector;

class IsPrime {                                                 
 public:
    IsPrime(int num): numb{num} {} 
    pair<bool, int> operator()() {
        for (int j = 2; j * j <= numb; ++j){
            if (numb % j == 0) return make_pair(false, numb);
        }
        return make_pair(true, numb);
    }
 private:
    int numb;       
};

class ActiveObject {
 public:
    
    future<pair<bool, int>> enqueueTask(int i) {
        IsPrime isPrime(i);
        packaged_task<pair<bool, int>()> newJob(isPrime);
        auto isPrimeFuture = newJob.get_future();
        {
            lock_guard<mutex> lockGuard(activationListMutex);
            activationList.push_back(move(newJob));            
        }
        return isPrimeFuture;
    }

    void run() {
        std::jthread j([this] {                                 
            while ( !runNextTask() );                           
        });
    }

 private:

    bool runNextTask() {                                        
        lock_guard<mutex> lockGuard(activationListMutex);
        auto empty = activationList.empty();
        if (!empty) {                                          
            auto myTask= std::move(activationList.front());
            activationList.pop_front();
            myTask();
        }
        return empty;
    }

    deque<packaged_task<pair<bool, int>()>> activationList;     
    mutex activationListMutex;
};

vector<int> getRandNumbers(int number) {
    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<> dist(1'000'000, 1'000'000'000);  
    vector<int> numbers;
    for (long long i = 0 ; i < number; ++i) numbers.push_back(dist(engine)); 
    return numbers;
}

future<vector<future<pair<bool, int>>>> getFutures(ActiveObject& activeObject, 
                                                   int numberPrimes) {
    return async([&activeObject, numberPrimes] {
        vector<future<pair<bool, int>>> futures;
        auto randNumbers = getRandNumbers(numberPrimes);       
        for (auto numb: randNumbers){
            futures.push_back(activeObject.enqueueTask(numb));  
        }
        return futures;
    });
}
    

int main() {
    
    cout << boolalpha << '\n';
    
     ActiveObject activeObject;
        
    // a few clients enqueue work concurrently                  
    auto client1 = getFutures(activeObject, 1998);
    auto client2 = getFutures(activeObject, 2003);
    auto client3 = getFutures(activeObject, 2011);
    auto client4 = getFutures(activeObject, 2014);
    auto client5 = getFutures(activeObject, 2017);
    
    // give me the futures                                      
    auto futures = client1.get();
    auto futures2 = client2.get();
    auto futures3 = client3.get();
    auto futures4 = client4.get();
    auto futures5 = client5.get();
    
    // put all futures together                                 
    futures.insert(futures.end(),make_move_iterator(futures2.begin()), 
                                 make_move_iterator(futures2.end()));
    
    futures.insert(futures.end(),make_move_iterator(futures3.begin()), 
                                 make_move_iterator(futures3.end()));
    
    futures.insert(futures.end(),make_move_iterator(futures4.begin()), 
                                 make_move_iterator(futures4.end()));
    
    futures.insert(futures.end(),make_move_iterator(futures5.begin()), 
                                 make_move_iterator(futures5.end()));
        
    // run the promises                                         
    activeObject.run();
    
    // get the results from the futures
    vector<pair<bool, int>> futResults;
    futResults.reserve(futures.size());
    for (auto& fut: futures) futResults.push_back(fut.get());   
    
    sort(futResults.begin(), futResults.end());                 
    
    // separate the primes from the non-primes
    auto prIt = find_if(futResults.begin(), futResults.end(), 
                        [](pair<bool, int> pa){ return pa.first == true; });
 
    cout << "Number primes: " << distance(prIt, futResults.end()) << '\n';       
    cout << "Primes:" << '\n';
    for_each(prIt, futResults.end(), [](auto p){ cout << p.second << " ";} );    
    
    cout << "\n\n";
    
    cout << "Number no primes: " << distance(futResults.begin(), prIt) << '\n';  
    cout << "No primes:" << '\n';
    for_each(futResults.begin(), prIt, [](auto p){ cout << p.second << " ";} );
    
    cout << '\n';
    
}