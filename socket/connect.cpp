// connect.cpp - реализация методов класса socketbsd для установки соединения с удаленным сокетом


#include "error.h"

#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Version 1

			void socketbsd::sockconnect(socketbsd & remsock)

				{
				
					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::opened)
         				
         					throw sockerrbsd(-4, "socketbsd", "void sockconnect(const socketbsd & remsock)");
         					
         					
         			// Проверка текущего состояния удаленного сокета и генерация исключения в случае ошибки
         			
         				if(remsock.state != status::closed)
         				
         					throw sockerrbsd(-2, "socketbsd", "void sockconnect(const socketbsd & remsock)");
         					
         					
         			// Проверка корректности инициализации семейства протоколов удаленного сокета
         			// и игенерация исключения в случае ошибки
         			
         				if(remsock.family != family)
         				
         					throw sockerrbsd(-7, "socketbsd", "void sockconnect(const socketbsd & remsock)");
         					
						
						// Соединение с удаленным сокетом и генерация исключения в случае ошибки

							if(connect(sockfd, remsock.p_addr_st->addr, remsock.p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", "void sockconnect(const socketbsd & remsock)");
								
						
						// Инициализация структуры адреса сокета объекта сокета через 
						// дескриптор сокета и генерация исключения в случае ошибки

							if(getsockname(sockfd, p_addr_st->addr, &p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", "void sockconnect(const socketbsd & remsock)");

								
						// Инициализация данных объекта сокета 

							dataInit();
							
							
						// Установка сокета в состояние "соединен"	
						
							state = status::connected;
							
							
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключения
					
						{
						
							excep.showmesg();
						
							exit(1);
						
						}
							

				} // void sockconnect(const socketbsd & remsock)



		// Version 2

			socketbsd *socketbsd::sockconnect(const char *ipaddr_, unsigned int port_) 

				{

					// Указатель на удаленный сокет
				
						socketbsd *p_remsock = 0;
						
					
					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::opened)
         				
         					throw sockerrbsd(-4, "socketbsd", 
         					
         						"socketbsd *sockconnect(const char *ipaddr_, unsigned int port_)");
         						
         			
         			// Создание объекта удаленного сокета
         			
         				p_remsock = new socketbsd;

         				p_remsock->family = family;
         						
         				p_remsock->type = type;
         						
         				p_remsock->protocol = protocol;
         				
         						
         				p_remsock->p_addr_st->setaddr(family);
         				
         				p_remsock->p_addr_st->writeIp(ipaddr_);
         				
         				p_remsock->p_addr_st->writePort(port_);
         				
         				p_remsock->dataInit();


						// Соединение с удаленным сокетом и генерация исключения в случае ошибки

							if(connect(sockfd, p_remsock->p_addr_st->addr, p_remsock->p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", 
								
									"socketbsd *sockconnect(const char *ipaddr_, unsigned int port_)");
								
						
						// Инициализация структуры адреса сокета объекта сокета через 
						// дескриптор сокета и генерация исключения в случае ошибки

							if(getsockname(sockfd, p_addr_st->addr, &p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", 
								
									"socketbsd *sockconnect(const char *ipaddr_, unsigned int port_)");

								
						// Инициализация данных объекта сокета 

							dataInit();

					
						// Установка сокета в состояние "находится в соединении с удаленным сокетом"
										
							state = status::connected;
						
						
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключения
					
						{
						
							excep.showmesg();
						
							exit(1);
						
						}
						
						
					return p_remsock;


				} // socketbsd *sockconnect(const char *ipaddr_, unsigned int port_) 


	} // namespace so
			
