// records.cpp

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

struct Rec { // (1)
    std::string name;
    std::string addr;
    int id;
};

int main()
{

    std::cout << std::endl;

    std::vector<Rec> vr { { "Grimm", "Munich", 1 }, // (2)
        { "huber", "Stuttgart", 2 },
        { "Smith", "Rottenburg", 3 },
        { "black", "Hanover", 4 } };

    std::string name = "smith";

    auto rec = std::find_if(vr.begin(), vr.end(), [&](Rec& r) { // (3)
        if (r.name.size() != name.size())
            return false;
        for (int i = 0; i < r.name.size(); ++i) {
            if (std::tolower(r.name[i]) != std::tolower(name[i]))
                return false;
        }
        return true;
    });

    if (rec != vr.end()) {
        std::cout << rec->name << ",  " << rec->addr << ", " << rec->id << std::endl;
    }

    std::cout << std::endl;
}
