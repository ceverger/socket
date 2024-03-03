// address.h - описание класса для работы со структурой адреса сокета SocketAddressBSD


#include <netdb.h>

#include <arpa/inet.h>


#ifndef SOCKET_ADDRESS_BSD_H_

#define SOCKET_ADDRESS_BSD_H_


	namespace so { // Пространсво имён сокетов


		class sockaddrbsd {


			public:


				struct sockaddr *addr; // Указатель на универсальную структура адреса сокета

            unsigned int size_addr; // Размер структуры адреса сокета


			private:			

		
        	   struct sockaddr_in addr4; // Структура адреса сокета IPv4
							 
        	   struct sockaddr_in6 addr6; // Структура адреса сокета IPv6



			public:


				// Конструкторы и деструкторы класса


					// Конструктор класса по умолчанию

               	sockaddrbsd();

					// Рользовательский конструктор

               	sockaddrbsd(int family);


					// Деструктор класса

						virtual ~sockaddrbsd() {}
						
						
						
				// Методы установки значений закрытых членов класса


					// Инициализация указателя на структуру адреса сокета 
					// в зависимости от семейства протоколов сокета

						void setaddr(int family);	


		
				// Методы для чтения данных из структуры адреса сокета
				

					// Чтение ip-адреса сокета

						unsigned int readIp(char *ipaddr, unsigned int addrlen) const;
						
					// Чтение номера порта сокета

						unsigned int readPort() const;



				// Методы для записи данных в структуру адреса сокета
							

					// Запись ip-адреса сокета

      				unsigned int writeIp(const char *ipaddr);	

					// Запись порта сокета

						void writePort(unsigned int port);			
							   

		}; // sockaddrbsd


	} // namespace so


#endif // SOCKET_ADDRESS_BSD_H_

