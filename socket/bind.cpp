// bind.cpp - реализация метода класса socketbsd для назначеия сокету ip-адреса и порта


#include <cerrno>

#include "error.h"

#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Version 1

			void socketbsd::sockbind()

				{
				
					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::opened)        				
         				
         					throw sockerrbsd(-4, "socketbsd", "void sockbind()");
         					
         					
         			// Назначение ip-адреса и порта сокету, а также генерация исключения в случае ошибки

							if(bind(sockfd, p_addr_st->addr, p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", "void sockbind()");
					
								
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключения
					
						{
						
							excep.showmesg();
						
							exit(1);
						
						}
					

				} // void sockbind()



		// Version 2

			void socketbsd::sockbind(const char *ipaddr_, unsigned int port_)


				{

					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::opened)
         				
         					throw sockerrbsd(-4, "socketbsd", 
         					
         						"void sockbind(const char *ipaddr_, unsigned int port_)");
 
         					
         			// Инициализация ip-адреса и пора сокета
         			
         				setip(ipaddr_);

							setport(port_);
         					
         					
         			// Назначение ip-адреса и порта сокету, а также генерация исключения в случае ошибки

							if(bind(sockfd, p_addr_st->addr, p_addr_st->size_addr) < 0)
							
								throw sockerrbsd(errno, "socketbsd", 
								
									"void sockbind(const char *ipaddr_, unsigned int port_)");
							
								
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключения
					
						{
						
							excep.showmesg();
						
							exit(1);
						
						}

				} // void sockbind(const char *ipaddr, unsigned int port)


	} // namespace so
