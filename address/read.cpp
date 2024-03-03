// read.cpp - реализация методов класса SocketAddressBSD для чтения данных из структуры адреса сокета


#include <cerrno>

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Чтение ip-адреса из структуры адреса сокета

			unsigned int sockaddrbsd::readIp(char *ipaddr, unsigned int addrlen) const

				{

					const void *p_addr = 0;
					
					int family = addr->sa_family;


					switch(family) { // Инициализация указателя ня структуру ip-адреса сокета


						case AF_INET:	p_addr = &addr4.sin_addr; break;

						case AF_INET6: p_addr = &addr6.sin6_addr; break;
						
						default: p_addr = &addr4.sin_addr;			

					}
					
					
					// Преобразование сетевого адреса из числового представления 
					// в строку, запись стрки в буфер и возврат статуса завершения операции           

						if(inet_ntop(family, p_addr, ipaddr, addrlen) < 0) return errno;
						
						
					return 0;
									
				
				}	// unsigned int readIp(char *ipaddr, unsigned int addrlen) const



		// Чтение порта из структуры адреса сокета

			unsigned int sockaddrbsd::readPort() const

				{

					int port = 0;
					
					int family = addr->sa_family;


					switch(family) {
						
						case AF_INET: port = ntohs(addr4.sin_port); break;

						case AF_INET6: port = ntohs(addr6.sin6_port); break;
						
						default: port = ntohs(addr4.sin_port);

					}


					return port;

				}


	} // namespace SO


		

