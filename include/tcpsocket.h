// tcpsoket.h - описание классов TcpSocketBSD для работа с tcp-сокетами 


#include "socket.h"


#ifndef TCP_SOCKET_BSD_H_
#define TCP_SOCKET_BSD_H_


	namespace so { // Пространсво имён сокетов
	
	
		// Класс tcp-сокета
	
			class tcpsocketbsd : public socketbsd {
		
		
				public:
							
					
					// Конструктор класса по умолчанию
				
						tcpsocketbsd(	const char *ipaddr = 0, // Строка с ip-адресом сокета	
									 
						/**********/ 	unsigned int port = 0,  // Порт сокета
							
						/**********/	const domain & d = ipv4   // Идентификатор семейства протоколов
									 
										);
									
									
					// Деструктор сокета
				
						virtual ~tcpsocketbsd() {}
		
		
			}; // tcpsocketbsd
			

				
		// Класс однопоточного tcp-сервера
		
			class tcpserverbsd : public tcpsocketbsd {
			
			
				private:
				
				
					
			
			};
	
	
	} // namespace SO
	
	
#endif // TCP_SOCKET_BSD_H_
