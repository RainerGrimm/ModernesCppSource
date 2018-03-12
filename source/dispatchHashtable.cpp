// dispatchHashtable.cpp

#include <chrono>
#include <functional>
#include <iostream>
#include <unordered_map>

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

std::unordered_map<MessageSeverity, std::function<void()>> mess2Func{
    {MessageSeverity::information, writeInformation},
    {MessageSeverity::warning, writeWarning},
    {MessageSeverity::fatal, writeUnexpected}
};

void writeMessage(MessageSeverity messServer){
	
	writeElapsedTime();
	
	mess2Func[messServer]();
	
}

int main(){

  std::cout << std::endl;
  
  writeMessage(MessageSeverity::information);
  writeMessage(MessageSeverity::warning);
  writeMessage(MessageSeverity::fatal);

  std::cout << std::endl;

}
