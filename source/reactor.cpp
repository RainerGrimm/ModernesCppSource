// reactor.cpp

#include <fstream>
#include <string>

#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Observer.h"
#include "Poco/Thread.h"
#include "Poco/Util/ServerApplication.h"

using Poco::Observer;
using Poco::Thread;

using Poco::Net::ReadableNotification;
using Poco::Net::ServerSocket;
using Poco::Net::ShutdownNotification;
using Poco::Net::SocketAcceptor;
using Poco::Net::SocketReactor;
using Poco::Net::StreamSocket;

using Poco::Util::Application;

class EchoHandler {
 public:
  EchoHandler(const StreamSocket& s, SocketReactor& r): socket(s), reactor(r) {
    reactor.addEventHandler(socket, 
      Observer<EchoHandler, ReadableNotification>(*this, &EchoHandler::socketReadable));
  }

  void socketReadable(ReadableNotification*) {
    char buffer[8];
    int n = socket.receiveBytes(buffer, sizeof(buffer));
    if (n > 0) {
      socket.sendBytes(buffer, n);
    }
    else {
      reactor.removeEventHandler(socket,
	      Observer<EchoHandler, ReadableNotification>(*this, &EchoHandler::socketReadable));
      delete this;
    }
  }

 private:
  StreamSocket socket;
  SocketReactor& reactor;
};

class DataHandler {
 public:

  DataHandler(StreamSocket& s, SocketReactor& r): socket(s), reactor(r), 
                                                  outFile("reactorOutput.txt") {
    reactor.addEventHandler(socket, 
      Observer<DataHandler, ReadableNotification>(*this, &DataHandler::socketReadable));
    reactor.addEventHandler(socket, 
      Observer<DataHandler, ShutdownNotification>(*this, &DataHandler::socketShutdown));
    socket.setBlocking(false);
  }

  ~DataHandler() {
    reactor.removeEventHandler(socket, 
      Observer<DataHandler, ReadableNotification>(*this, &DataHandler::socketReadable));
    reactor.removeEventHandler(socket, 
      Observer<DataHandler, ShutdownNotification>(*this, &DataHandler::socketShutdown));
  }

  void socketReadable(ReadableNotification*) {
    char buffer[64];
    int n = 0;
    do {
      n = socket.receiveBytes(&buffer[0], sizeof(buffer));
      if (n > 0) {
        std::string s(buffer, n);
        outFile << s << std::flush;
      }
      else break;
    } while (true);
  }

  void socketShutdown(ShutdownNotification*) {
    delete this;
  }

 private:
  StreamSocket socket;
  SocketReactor& reactor;
  std::ofstream outFile;
};

class Server: public Poco::Util::ServerApplication {

 protected:
  void initialize(Application& self) {
    ServerApplication::initialize(self);
  }
		
  void uninitialize() {
    ServerApplication::uninitialize();
  }

  int main(const std::vector<std::string>&) {
		
    ServerSocket serverSocketEcho(4711);
    ServerSocket serverSocketData(4712);
    SocketReactor reactor;
    SocketAcceptor<EchoHandler> acceptorEcho(serverSocketEcho, reactor);
    SocketAcceptor<DataHandler> acceptorData(serverSocketData, reactor);
    Thread thread;
    thread.start(reactor);
    waitForTerminationRequest();
    reactor.stop();
    thread.join();
        
    return Application::EXIT_OK;

  }

};

int main(int argc, char** argv) {

  Server app;
  return app.run(argc, argv);

}