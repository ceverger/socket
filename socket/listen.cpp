// listen.cpp - реализация метода класса socketbsd установки сокета в прослушиваемое состояние


#include <cerrno>

#include "error.h"

#include "socket.h"

#include <arpa/inet.h>


	namespace so { // Пространсво имён сокетов


		void socketbsd::socklisten(unsigned int count)

			{
			
				try { // Блок отслеживания исключений
					
					
					// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         			if(state != status::opened)        				
         				
         				throw sockerrbsd(-4, "socketbsd", "void socklisten(int)");
         				
         		
         		// Инициализация количества прослушивамых соединений
         		
         			count = (count > 0) ? count : 1;  
         				
         				
         		// Установка сокета в прослушиваемое состояние и генерация исключения в случае ошибки

						if(listen(sockfd, count) < 0)
						
							throw sockerrbsd(errno, "socketbsd", "void socklisten(int)");

  						state = status::listened;

 
 				} // try
 				
 				
 				catch(sockerrbsd & excep) // Обработка исключения
					
					{
						
						excep.showmesg();
						
						exit(1);
						
					}
 					
			
			} // void socklisten(void)


	}	// namespace so
