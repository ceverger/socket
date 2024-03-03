// set.cpp - реализация методов для инициализации закрытых членов класса socketbsd


#include "error.h"

#include <cstring>

#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Установка семейства протоколов для сокета

			void socketbsd::setfamily(const domain & f)

         	{
         	
         		try { // Блок отслеживания исключений
         		
         		
         			// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::closed)
         				
         					throw sockerrbsd(-2, "socketbsd", "void setfamily(domain)");
         					
         			
         			// Инициализация семейства протоколов сокета

			   			family = familyInit(f.getid());
			   			
			   			
			   		// Проверка состояния инициализации семейства протоколов сокета 
         			// и генерация исключения в случае ошибки
         			
         				if(family == UNKNOW_VALUE)
         				
         					throw sockerrbsd(-4, "socketbsd", "void setfamily(domain)");
         					
         					
         			// Инициализация указателя на универсальную структуру адреса сокета	

							p_addr_st->setaddr(family); 
							
							
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключений 
					
						{ 
					
							excep.showmesg();
					
						}


				} // void setfamily(domain f)


        
		// Установка типа сокета

         void socketbsd::settype(const sort & t)

         	{
         	
         		try { // Блок отслеживания исключений
         		
         		
         			// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::closed)
         				
         					throw sockerrbsd(-2, "socketbsd", "void settype(sort)");
         					
         			
         			// Инициализация типа сокета

			   			type = typeInit(t.getid());
							
							
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключений 
					
						{ 
					
							excep.showmesg();
					
						}

               
				} // void settype(sort t)



		// Установка протокола сокета

      	void socketbsd::setprotocol(const transfer & p)

         	{
         	
 					try { // Блок отслеживания исключений
         		
         		
         			// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::closed)
         				
         					throw sockerrbsd(-2, "socketbsd", "void setprotocol(transfer)");
         					
         			
         			// Инициализация протокола сокета

			   			protocol = protocolInit(p.getid());
							
							
					} // try


					catch(sockerrbsd & excep) // Обработка исключений 
					
						{ 
					
							excep.showmesg();
					
						}


				} // void setprotocol(transfer p)



		// Установка ip-адреса сокета

      	void socketbsd::setip(const char *ipaddr_)

         	{        		
         	
         		try { // Блок отслеживания исключений
         		
         		
         			// Номер ошибки
         		
         				int errnum;
         				
         		
         			// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::closed && state != status::opened)
         				
         					throw sockerrbsd(-3, "socketbsd", "void setip(const char *)");
         					
         			
         			// Проверка состояния инициализации семейства протоколов сокета 
         			// и генерация исключения в случае ошибки
         			
         				if(family == UNKNOW_VALUE)
         				
         					throw sockerrbsd(-4, "socketbsd", "void setip(const char *)");
       					
         			
         			// Инициализация ip-адреса сокета, если входящая строка его содержит,
         			// и запись его в структуру адреса сокета и генерация исключения в случае неудачи

			   			if(ipaddr_ != 0) strncpy(ipaddr, ipaddr_, SOCKET_ADDRESS_MAX_LEN);		   					
			   					
			   			if((errnum = p_addr_st->writeIp(ipaddr)) > 0)		   			
			   					
			   				throw sockerrbsd(errnum, "sockaddrbsd", "void writeIp(const char *ipaddr_)");
							
							
					} // try
	
					
					catch(sockerrbsd & excep) // Обработка исключений 
					
						{ 
					
							excep.showmesg();
							
					
						}
				
                            
				} // void setip(const char *ipaddr_)


        
		// Установка порта сокета 

			void socketbsd::setport(unsigned int port_)

				{
				
					try { // Блок отслеживания исключений
         		
         		
         			// Проверка текущего состояния сокета и генерация исключения в случае ошибки
         			
         				if(state != status::closed && state != status::opened)
         				
         					throw sockerrbsd(-3, "socketbsd", "void setport(unsigned int)");
         					
         					
         			// Проверка состояния инициализации семейства протоколов сокета 
         			// и генерация исключения в случае ошибки
         			
         				if(family == UNKNOW_VALUE)
         				
         					throw sockerrbsd(-4, "socketbsd", "void setport(unsigned int)");
         					
         			
         			// Инициализация порта сокета и запись его в структуру адреса сокета
         			
         				port = port_;

			   			p_addr_st->writePort(port);
							
							
					} // try
	
					
					catch(sockerrbsd & excep) // Обработка исключения
					
						{ 
					
							excep.showmesg();
					
						}


				} // void setport(unsigned int port_)


    } // namespace so
