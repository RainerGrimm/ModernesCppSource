// sortVariations.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool greater(const std::string& first, const std::string& second) {
    return first > second;
}

int main(){

    std::vector<std::string> myStrings{"Only", "for", "testing", "purpose", "."};

    // sort ascending
    std::sort(myStrings.begin(), myStrings.end());

    // sort descending 
    std::sort(myStrings.begin(), myStrings.end(), greater);
    std::sort(myStrings.begin(), myStrings.end(), std::greater<std::string>());
    std::sort(myStrings.begin(), myStrings.end(), [](const std::string& first, const std::string& second) {
                                                      return first > second; 
                                                    });

    // sort based on the length of the strings
    std::sort(myStrings.begin(), myStrings.end(), [](const std::string& first, const std::string& second) {
                                                      return first.length() < second.length(); 
                                                    });

}