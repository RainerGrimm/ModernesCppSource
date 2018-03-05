// switchDict.cpp

#include <functional>
#include <iostream>
#include <unordered_map>

enum class Message{
  information,
  warning,
  error,
  fatal
};

void writeMessage(){ std::cerr << "message" << std::endl; }
void writeWarning(){ std::cerr << "warning" << std::endl; }
void writeUnexpected(){ std::cerr << "unexpected" << std::endl; }

std::unordered_map<Message, std::function<void()>> mess2Func{
    {Message::information, writeMessage},
    {Message::warning, writeWarning}
};

void withDefault(Message mess){
    
  auto pair = mess2Func.find(mess);
  if (pair != mess2Func.end()){
      pair->second();
  }
  else{
      writeUnexpected();
  }
  
}

void withoutDefaultGood(Message mess){

  auto pair = mess2Func.find(mess);
  if (pair != mess2Func.end()){
      pair->second();
  }
  else{
      // Nothing can be done
  }
  
}

void withoutDefaultBad(Message mess){
  
  auto pair = mess2Func.find(mess);
  if (pair != mess2Func.end()){
      pair->second();
  }
  
}

int main(){

  std::cout << std::endl;
  
  withDefault(Message::fatal);
  withoutDefaultGood(Message::information);
  withoutDefaultBad(Message::warning);

  std::cout << std::endl;

}
