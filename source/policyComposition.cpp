// policyComposition.cpp

#include <iostream>
#include <fstream>
#include <string>

template <typename OutputPolicy>
class Message {
 public:
    void write(const std::string& mess) const {
        outPolicy.print(mess);
    }
 private:
    OutputPolicy outPolicy;   
};

class WriteToCout {
 public:
    void print(const std::string& message) const {
        std::cout << message << '\n';
    }
};

class WriteToFile {
 public:
    void print(const std::string& message) const {
        std::ofstream myFile;
        myFile.open("policyComposition.txt");
        myFile << message << '\n';
    }
};


int main() {

    Message<WriteToCout> messageCout;
    messageCout.write("Hello world");

    Message<WriteToFile> messageFile;
    messageFile.write("Hello world");

}
