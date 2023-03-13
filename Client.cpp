#include "socket.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

using namespace Sync;

int main(void)
{
	string userInput = " ";
	std::cout << "I am a client" << std::endl;

	Socket sock("127.0.0.1",3000);
	std::cout << "Made it here" << std::endl;


	//sock.Open();
	//connects to the server
	if(sock.Open()){

		std::cout<<"Client has connected"<<endl;
		while(userInput != "Done"){
		
		//asks client to type somthing
		std::cout << "I am a client please type somthing" << std::endl;
		std::cin >> userInput;

		//writes to the server
		sock.Write(ByteArray(userInput));
		ByteArray alterMessage;

		//reads the return message from the Server
		sock.Read(alterMessage);
		std::cout<<"The new message: "<< alterMessage.ToString()<<std::endl;


		}

		sock.Close();



	}
  

	
	
}
