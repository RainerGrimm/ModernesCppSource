// telephoneBook.cpp

#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using map = std::unordered_map<std::string, int>;                   // (1)

std::ifstream openFile(const std::string& myFile){                  

  std::ifstream file(myFile, std::ios::in);
  if ( !file ){
    std::cerr << "Can't open file "+ myFile + "!" << std::endl;
    exit(EXIT_FAILURE);
  }
  return file;
  
}

std::string readFile(std::ifstream file){                        
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
    
}

map createTeleBook(const std::string& fileCont){                 
    
    map teleBook; 
    
    std::regex regColon(":");
    
    std::sregex_token_iterator fileContIt(fileCont.begin(), fileCont.end(), regColon, -1);
    const std::sregex_token_iterator fileContEndIt;
    
    std::string entry;
    std::string key;
    int value;
    while (fileContIt != fileContEndIt){
        entry = *fileContIt++;
        auto comma = entry.find(",");
        key = entry.substr(0, comma);
        value = std::stoi(entry.substr(comma + 1, entry.length() -1));
        teleBook[key] = value;
    }
    return teleBook;
    
}

std::vector<std::string> getRandomNames(const map& teleBook){    
    
    std::vector<std::string> allNames;
    for (const auto& pair: teleBook) allNames.push_back(pair.first);
    
    std::random_device randDev;
    std::mt19937 generator(randDev());
 
    std::shuffle(allNames.begin(), allNames.end(), generator);
    
    return allNames;
}
    
void measurePerformance(const std::vector<std::string>& names, map& m){   
        
    auto start = std::chrono::steady_clock::now();
    for (const auto& name: names) m[name];
    std::chrono::duration<double> dur= std::chrono::steady_clock::now() - start;
    std::cout << "Access time: " << dur.count() << " seconds" << std::endl;
    
}
    
int main(int argc, char* argv[]){

    std::cout << std::endl;
  
    // get the filename
    std::string myFile;
    if ( argc == 2 ){
        myFile= {argv[1]};
    }
    else{
        std::cerr << "Filename missing !" << std::endl;
        exit(EXIT_FAILURE);
    } 
  
    std::ifstream file = openFile(myFile);
  
    std::string fileContent = readFile(std::move(file));
  
    map teleBook = createTeleBook(fileContent);
  
    std::cout << "teleBook.size(): " <<  teleBook.size() << std::endl;
  
    std::vector<std::string> randomNames = getRandomNames(teleBook);
  
    measurePerformance(randomNames, teleBook); 
    
    std::cout << std::endl;
    
}
