// policyInheritance.cpp

#include <iostream>
#include <fstream>
#include <string>

template <typename OutputPolicy>
class Message : private OutputPolicy {
 public:
    void write(const std::string& mess) const {
        print(mess);
    }
 private:
    using OutputPolicy::print;
};

class WriteToCout {
 protected:
    void print(const std::string& message) const {
        std::cout << message << '\n';
    }
};

class WriteToFile {
 protected:
    void print(const std::string& message) const {
        std::ofstream myFile;
        myFile.open("policyInheritance.txt");
        myFile << message << '\n';
    }
};


int main() {

    Message<WriteToCout> messageCout;
    messageCout.write("Hello world");

    Message<WriteToFile> messageFile;
    messageFile.write("Hello world");

}
