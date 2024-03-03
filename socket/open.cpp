// open.cpp - реализация методов для открытия и закрытия сокета класса socketbsd


#include "error.h"

#include <cerrno>

#include <netdb.h>

#include <unistd.h>

#include "socket.h"


	namespace so { // Пространсво имён сокетов

	
	// Открытие сокета

		void socketbsd::sockopen(void)

			{
				
			
				try { // Блок отслеживания исключений
				
				
					// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         			if(state != status::closed)
         				
         				throw sockerrbsd(-2, "socketbsd", "void sockopen(void)");
         					
         			
         		// Проверка состояния инициализации семейства протоколов сокета 
         		// и генерация исключения в случае ошибки
         			
         			if(family == UNKNOW_VALUE)
         				
         				throw sockerrbsd(-4, "socketbsd", "void sockopen(void)");


					// Получение файлового дескриптора и генерация исключения в случае ошибки

     		   		if((sockfd = socket(family, type, protocol)) < 0)
     		   		
     		   			throw sockerrbsd(errno, "socketbsd", "void sockopen(void)");  
     		   			 		   			
     		   	
					// Инициализация состояния сокета

						state = status::opened;
     		   			
     		   } // try	
					
					
				catch(sockerrbsd & excep) // Обработка исключенияы
				
					{
					
						excep.showmesg();
						
						exit(1);
					
					}

                
			} // void sockopen(void)



		// Закрытие сокета

      	void socketbsd::sockclose(void)

				{


					try { // Блок отслеживания исключений


						// Закрытие сокета и генерация исключения в случае ошибки

     		   			if(close(sockfd) < 0)
     		   		
     		   				throw sockerrbsd(errno, "socketbsd", "void sockclose(void)");
     		   				
     		   				
     		   		// Установка сокета в закрытое состояние и инициализация 
     		   		// файлового дескриптора неизвестным значением
     		   		
     		   			state = status::closed;

        	      		sockfd = UNKNOW_VALUE;	
     		   			
     		   			
     		   	} // try				       


        	      catch(sockerrbsd & excep) // Обработка исключения
				
						{
					
							excep.showmesg();
						
							exit(1);
					
						}


				} // void sockclose(void)
    

    } // namespace so
