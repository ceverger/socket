// oper.cpp - реализация методов с перегрузками операций для класса SocketBSD


#include <iostream>

#include "socket.h"

#include <arpa/inet.h>


	namespace so { // Пространсво имён сокетов
	
	
		// Перегрузка операции для вывода содержимого экземпляря класса SocketBSD
		
			std::ostream & operator<<(std::ostream & os, const socketbsd & sock)

				{
				
					const char *status;		// Строка с нименем состояния сокета
				
					const char *domain; 		// Строка с именем семейства протоколов сокета

					const char *kind;			// Строка с именем типа сокета

					const char *stack;		// Строка с именем протокола сокета 
					
					const char *ipaddress;	// Строка с ip-адресом сокета
					
					
					switch(sock.state) {

						case status::closed: status = "closed"; break;

						case status::opened: status = "opened"; break;
						
						case status::connected: status = "connected"; break;

						case status::listened: status = "listened"; break;

						default: status = "unknow";
			
					}
					
					
					switch(sock.family) {

						case AF_INET: domain = "ipv4"; break;

						case AF_INET6: domain = "ipv6"; break;

						default: domain = "Unknow";

					}
					
					
					switch(sock.type) {

						case SOCK_STREAM: kind = "stream"; break;

						case SOCK_DGRAM: kind = "dgram"; break;

						case SOCK_SEQPACKET: kind = "packet"; break;

						default: kind = "unknow";
					
					
					}
				
				
					switch(sock.protocol) {

						case IPPROTO_TCP: stack = "tcp"; break;

						case IPPROTO_UDP: stack = "udp"; break;

						case IPPROTO_SCTP: stack = "sctp"; break;

						default: stack = "unknow";	
						
					}
					
					
					
					ipaddress = (*sock.ipaddr == 0) ? "any" : sock.ipaddr;
					
					
					os << "Сокет " << ipaddress << ":" << sock.port 
	
	   		   	<< "; Семейство протоколов - " << domain

	   		   	<< "; Тип - " << kind

	   		   	<< "; Протокол - " << stack

	   	       	<< "; Состояние - " << status

	   		   	<< "; Номер файлового дескриптора " << sock.sockfd 

						<< ";"<< std::endl; 
	   		   
	   		   	   		   
	   			return os;
										
					
				}	// std::ostream & operator<<(std::ostream & os, const SocketBSD & sock)


	} // namespace so
