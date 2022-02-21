// dispatchDynamicPolymorphism.cpp

#include <chrono>
#include <iostream>

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

struct MessageSeverity{                         
	virtual void writeMessage() const {         
		std::cerr << "unexpected" << '\n';
	}
};

struct MessageInformation: MessageSeverity{     
	void writeMessage() const override {        
		std::cerr << "information" << '\n';
	}
};

struct MessageWarning: MessageSeverity{         
	void writeMessage() const override {        
		std::cerr << "warning" << '\n';
	}
};

struct MessageFatal: MessageSeverity{};

void writeMessageReference(const MessageSeverity& messServer){
	
	writeElapsedTime();
	messServer.writeMessage();
	
}

void writeMessagePointer(const MessageSeverity* messServer){
	
	writeElapsedTime();
	messServer->writeMessage();
	
}

int main(){

    std::cout << '\n';
  
    MessageInformation messInfo;
    MessageWarning messWarn;
    MessageFatal messFatal;
  
    MessageSeverity& messRef1 = messInfo;            
    MessageSeverity& messRef2 = messWarn;
    MessageSeverity& messRef3 = messFatal;
  
    writeMessageReference(messRef1);              
    writeMessageReference(messRef2);
    writeMessageReference(messRef3);
  
    std::cerr << '\n';
  
    MessageSeverity* messPoin1 = new MessageInformation;
    MessageSeverity* messPoin2 = new MessageWarning;
    MessageSeverity* messPoin3 = new MessageFatal;
  
    writeMessagePointer(messPoin1);               
    writeMessagePointer(messPoin2);
    writeMessagePointer(messPoin3);
  
    std::cout << '\n';

}
