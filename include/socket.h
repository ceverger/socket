// socket.h - описание класса socketbsd для работы с сокетами 


#include "type.h"

#include "domain.h"

#include "sort.h"

#include "transfer.h"


#include <iostream>


#ifndef SOCKET_BSD_H_

#define SOCKET_BSD_H_  


	namespace so { // Пространсво имён сокетов
	

		// Предварительное объявление класса для работы со структурой адреса сокета

			class sockaddrbsd;


		// Объявление класса для работы с сокетами

			class socketbsd {
                       
	
				private: 


					int state; //Состояние сокета

	
			   	int family; //Семейство сокета
	
        	   	int type; //Тип сокета
	
        	   	int protocol; //Протокол сокета


            	char ipaddr[SOCKET_ADDRESS_MAX_LEN]; //IP-адрес сокета

            	unsigned int port; //Порт сокета

					sockaddrbsd *p_addr_st; // Указатель на класс структуры адреса сокета


	    	   	int sockfd; // Файловый дескриптор сокета

                
            	int familyInit(int id);	  // Инициализация семейсва протоколов сокета по идентификатору семейства протоколов сокета

            	int typeInit(int id); 	  // Инициализация типа сокета по идентификатору типа сокета

            	int protocolInit(int id); // Инициализаия протокола сокета по идентификатору протокола сокета


					void dataInit(void); // Инициализация закрытых членов класса значениями из структуры адреса сокета

					void addrInit(void); // Инициализация структуры адреса сокета значениями закрытых членов класса


				public:


					// Конструкторы и деструкторы класса


            		// Конструктор по умолчанию

               		socketbsd();

						// Пользовательский конструктор класса                    

	               	socketbsd( const domain & f, 			// Идентификатор семейства протоколов
			
			         	/*******/  const sort & t, 			// Идентификатор типа сокета
			
			        		/*******/  const transfer & p,		// Идентификатор номера протокола сокета

							/*******/  const char *ipaddr_ = 0, // Строка с ip-адресом сокета

							/*******/  unsigned int port = 0 	// Порт сокета

	        	               	);

               	// Деструктор по умолчанию

	               	virtual ~socketbsd();
	        


					// Методы для получения значений закрытых членов класса

	        	
	         		// Получение идентификатора состояня сокета

	        	   		int getstate(void) const; 

	            	// Получение идентификатора семейства сокета

            	   	int getfamily(void) const;

               	// Получение идентификатора типа сокета

            	   	int gettype(void) const;

               	// Получение идентификатора протокола сокета

	        	      	int getprotocol(void) const;

               	// Послучение строки ip-адреса сокета

                  	const char *getipaddr(void) const; 

               	// Получение номера порта сокета

                  	int getport(void) const;


					// Методы для установки значений закрытых данных членов класса


            		// Установка семейства протоколов для сокета

            			void setfamily(const domain & f);

              		// Установка типа сокета

            	  		void settype(const sort & t);

               	// Установка протокола сокета

            	   	void setprotocol(const transfer & p);

						// Установка ip-адреса сокета

							void setip(const char *ipaddr_);

						// Установка номера порта сокета

							void setport(unsigned int port);



					// Методы для работы с сокетом


						// Открытие и закрытие сокета

                  	void sockopen(void);

                  	void sockclose(void);

                
               	// Установка соединения с удаленным сокетом

							void sockconnect(socketbsd & remsock); // ver.1

                  	socketbsd *sockconnect(const char *ipaddr_, unsigned int port_); // ver.2


						// Назначение сокету ip-адреса и порта

							void sockbind(void); // ver.1

							void sockbind(const char *ipaddr_, unsigned int port_); // ver.2


						// Установка сокета в прослушиваемое состояние

							void socklisten(unsigned int count = 1);


						// Получение указателя на присоединенный сокет

							socketbsd *sockaccept(void); // ver.1

							socketbsd & sockaccept(socketbsd & sock); // ver.2
						
						
						// Методы чтения и записи в сокет
				
							int rddata(void *buffer, unsigned int size);
					
							int wrdata(const void *buffer, unsigned int size);
     
        
          		// Вывод содержимого объекта сокета в стандартный поток ввода вывода

               	friend std::ostream & operator<<(std::ostream & os, const socketbsd & sock);
	        

			}; // socketbsd
 

	} // namespace so



#endif // SOCKET_BSD_H_
