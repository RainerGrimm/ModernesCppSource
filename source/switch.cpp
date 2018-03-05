// switch.cpp

#include <iostream>

enum class Message{
  information,
  warning,
  error,
  fatal
};

void writeMessage(){ std::cerr << "message" << std::endl; }
void writeWarning(){ std::cerr << "warning" << std::endl; }
void writeUnexpected(){ std::cerr << "unexpected" << std::endl; }

void withDefault(Message mess){

  switch(mess){
    case Message::information:
      writeMessage();
      break;
    case Message:: warning:
      writeWarning();
      break;
    default:
      writeUnexpected();
      break;
  }
  
}

void withoutDefaultGood(Message mess){

  switch(mess){
    case Message::information:
      writeMessage();
      break;
    case Message:: warning:
      writeWarning();
      break;
    default:
      // nothing can be done
      break;
  }
  
}

void withoutDefaultBad(Message mess){

  switch(mess){
    case Message::information:
      writeMessage();
      break;
    case Message::warning:
      writeWarning();
      break;
  }
  
}

int main(){

  std::cout << std::endl;
  
  withDefault(Message::fatal);
  withoutDefaultGood(Message::information);
  withoutDefaultBad(Message::warning);

  std::cout << std::endl;

}
