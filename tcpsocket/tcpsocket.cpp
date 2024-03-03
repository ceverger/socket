// tcpsocket.cpp - реализация конструкторов и деструкторов класса TcpSocketBSD


#include "tcpsocket.h"


	namespace so { // Пространство имен сокетов
	
	
		// Конструктор класса по умолчанию
	
			tcpsocketbsd::tcpsocketbsd(const char *ipaddr, unsigned int port, const domain & d)
		
				: socketbsd(d, stream, tcp, ipaddr, port) 
			
					{}
 

	}; // namespace so
