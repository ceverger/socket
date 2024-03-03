// read.cpp - реализация метода класса socketbsd для чтения данных из сокета


#include <cerrno>

#include "error.h"

#include <unistd.h>

#include "socket.h"


	namespace so { // Пространство имен сокетов
	
	
		int socketbsd::rddata(void *buffer, unsigned int size)
		
			{
			
				try { // Блок для отслеживания исключений
				
				
					// Проверка на корректность аргментов метода и генерация исключения в случае ошибки
					
						if(buffer == 0)
						
							throw sockerrbsd(-10, "socketbsd", "void rddata(void *buffer, unsigned int size)");
							
						if(size == 0)
						
							throw sockerrbsd(-11, "socketbsd", "void rddata(void *buffer, unsigned int size)");
							
				
					// Проверка текущего состояния сокета и генерация исключения в случае ошибки
					
						if(state != status::connected)
					
							throw sockerrbsd(-5, "socketbsd", "void rddata(void *buffer, unsigned int size)");
							
				
					// Чтение данных из сокета, генерация исключения в случае ошибки и возврат количества считанных байт

						int ret = read(sockfd, buffer, size);
				
						if(ret < 0) throw sockerrbsd(errno, "socketbsd", "void rddata(void *buffer, unsigned int size)");

						return ret;
						
						
				} // try
				
				
				catch(sockerrbsd & excep) // Обработка исключения
				
					{
		
						excep.showmesg();

						return -1;
					
					}
						
			
			} // int rddata(void *buffer, unsigned int size)
		
	
	} // namespace so
