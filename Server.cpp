#include "thread.h"
#include "socketserver.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>

using namespace Sync;
using namespace std;

class serverThread: public Thread{
    public:

    

    virtual long ThreadMain(void) override{

        



    }


int main(void)
{
   

//Starts the sever  
SocketServer serSock(3000);
std::cout << "I am a server running on port 3000." << std::endl;


//waits till the client socket connects
Socket sock(serSock.Accept());
ByteArray message;

//gets the message from the client
std::cout << "The bytes of the message: "<< sock.Read(message)<<std::endl;
std::cout << "The Message: " << message.ToString()<<std::endl;

//alters the message
string altMessage = message.ToString();
for (auto & c: altMessage) c = toupper(c);
std::cout << "The altered Message: " << altMessage<<std::endl;

sock.Write(altMessage);


//std::cout << "The message: "<< message.ToString()<<std::endl;
}
