all : Writer Reader

Writer: Writer.o thread.o Blockable.o Mailbox.o
	g++ -o Writer Writer.o thread.o Blockable.o Mailbox.o -pthread -l rt

Reader: Reader.o thread.o Blockable.o Mailbox.o
	g++ -o Reader Reader.o Mailbox.o -pthread -l rt
	
Writer.o : Writer.cpp thread.h Blockable.h SharedObject.h  Mailbox.h Semaphore.h
	g++ -c Writer.cpp -std=c++11

thread.o : thread.cpp thread.h Blockable.h
	g++ -c thread.cpp -std=c++11

Blockable.o : Blockable.cpp Blockable.h
	g++ -c Blockable.cpp -std=c++11
	
Reader.o : Reader.cpp SharedObject.h Semaphore.h Mailbox.h
	g++ -c Reader.cpp -std=c++11 
