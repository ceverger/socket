// accept.cpp - реализация метода класса socketbsd для присоединения нового сокета


#include <cerrno>

#include "error.h"

#include "socket.h"

#include "address.h"


	namespace so {	// Пространсво имён сокетов


		// Version 1

			socketbsd *socketbsd::sockaccept()


				{

					socketbsd *p_connect  = 0; 
					
					
					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::listened)
         				
         					throw sockerrbsd(-6, "socketbsd", "socketbsd *sockaccept()");
         					
         					
         			// Создание и инициализация объекта данных присоединяемого сокета
         			
         				p_connect = new socketbsd;

							p_connect->family = family;
							
							p_connect->type = type;
							
							p_connect->protocol = protocol;

							p_connect->p_addr_st->setaddr(family);
							
							
						// Выполенние присоединения нового сокета и генерация исключения в случае ошибки
						
							p_connect->sockfd = accept(sockfd, p_connect->p_addr_st->addr, &p_connect->p_addr_st->size_addr);
							
							if(p_connect->sockfd < 0) 
							
								throw sockerrbsd(errno, "socketbsd", "socketbsd *sockaccept()");
							
							
						// Инициализация ip-адреса и порта присоединенного сокета через структуру адреса сокета
						// и установка присоединенного сокета в состояние соединения
						
							p_connect->dataInit();
							
							p_connect->state = status::connected;
        				
        			
         		} // try
         		
         		
         		catch(sockerrbsd & excep) // Обработка исключения
         		
         			{
         			
         				excep.showmesg();
						
							exit(1);
         			
         			}
         			
         			
         		return p_connect;
						
						
				} // socketbsd *sockaccept()



		// Version 2

			socketbsd & socketbsd::sockaccept(socketbsd & connect)

				{

					try { // Блок отслеживания исключений
					
					
						// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::listened)
         				
         					throw sockerrbsd(-6, "socketbsd", "socketbsd & sockaccept(socketbsd & connect)");
   
         					
         			// Проверка текущего состояния присоединяемого сокета и генерация исключения в случае ошибки
         			
         				if(connect.state != status::closed)
         					
         					throw sockerrbsd(-2, "socketbsd", "socketbsd & sockaccept(socketbsd & connect)");
 
         					
         			// Проверка корректности инициализации семейства протоколов присоединяемого сокета
         			// и инициализация его, в случае необходимости
         			
         				if(connect.family != family)
         				
         					{
         					
         						connect.family = family;
         						
         						connect.type = type;
         						
         						connect.protocol = protocol;
         						
         						connect.p_addr_st->setaddr(family);
         						       					
         					}
							
							
						// Выполенние присоединения нового сокета и генерация исключения в случае ошибки
						
							connect.sockfd = accept(sockfd, connect.p_addr_st->addr, &connect.p_addr_st->size_addr);
							
							if(connect.sockfd < 0) 
							
								throw sockerrbsd(errno, "socketbsd", "socketbsd & sockaccept(socketbsd & connect)");
							
							
						// Инициализация ip-адреса и порта присоединенного сокета через структуру адреса сокета
						// и установка присоединенного сокета в состояние соединения
						
							connect.dataInit();
							
							connect.state = status::connected;
        				
        			
         		} // try
         		
         		
         		catch(sockerrbsd & excep) // Обработка исключения
         		
         			{
         			
         				excep.showmesg();
						
							exit(1);
         			
         			}
         			
         			
         		return connect;
         		
				
				} // socketbsd & sockaccept(socketbsd & connect)


	} // namespace so
