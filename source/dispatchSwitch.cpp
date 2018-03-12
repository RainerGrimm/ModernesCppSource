// dispatchSwitch.cpp

#include <chrono>
#include <iostream>

enum class MessageSeverity{
    information,
    warning,
    fatal,
};

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

void writeInformation(){ std::cerr << "information" << std::endl; }
void writeWarning(){ std::cerr << "warning" << std::endl; }
void writeUnexpected(){ std::cerr << "unexpected" << std::endl; }

void writeMessage(MessageSeverity messSever){
	
    writeElapsedTime();

    switch(messSever){
        case MessageSeverity::information:
            writeInformation();
            break;
        case MessageSeverity::warning:
            writeWarning();
            break;
        default:
            writeUnexpected();
            break;
  }
  
}

int main(){

    std::cout << std::endl;
  
    writeMessage(MessageSeverity::information);
    writeMessage(MessageSeverity::warning);
    writeMessage(MessageSeverity::fatal);

    std::cout << std::endl;

}
