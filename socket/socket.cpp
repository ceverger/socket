// socket.cpp - реализация конструкторов и деструкторов объектов класса socketbsd


#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Конструктор класса по умолчанию

         socketbsd::socketbsd()

         	{

					// Задание исходного состояния сокета
    
            		state = status::closed;


					// Инициализация переменных свойств сокета

               	family = UNKNOW_VALUE;

               	type = UNKNOW_VALUE;

               	protocol = UNKNOW_VALUE;


					// Заполнение всего массива ip-адреса терминальными нулями

               	for(int i = 0; i < SOCKET_ADDRESS_MAX_LEN; ++i) ipaddr[i] = '\0';

					// Инициализация порта сокета

               	port = 0;


					// Создание объекта управления структурой адреса сокета

               	p_addr_st = new sockaddrbsd();


					// Инициализация начальными значениями файловых дескрипторов сокета и номера ошибки

               	sockfd = UNKNOW_VALUE;

                
				} // socketbsd()        


		// Пользовательский конструктор класса

			socketbsd::socketbsd(const domain & f, const sort & t, const transfer & p, 
			
											const char *ipaddr_, unsigned int port_)

		   	{

					// Задание исходного состояния сокета

						state = status::closed;


					// Инициализация переменных свойств сокета

						family = familyInit(f.getid());

						type = typeInit(t.getid());

						protocol = protocolInit(p.getid());


					// Заполнение всего массива ip-адреса терминальными нулями

						for(int i = 0; i < SOCKET_ADDRESS_MAX_LEN; ++i) ipaddr[i] = '\0';

					// Инициализация порта сокета начальным значением

			      	port  = 0;

					// Создание объекта управления структурой адреса сокета                

               	p_addr_st = new sockaddrbsd(family);


					// Инициализация ip-адреса и порта новыми значениями
					
						setip(ipaddr_);

						setport(port_);


					// Инициализация начальными значениями файловых дескрипторов сокета и номера ошибки

			      	sockfd = UNKNOW_VALUE;

                
				} // socketbsd(domain f, sort t, transfer p, const char *ipaddr_, unsigned int port_)


		// Деструктор класса по умолчанию

			socketbsd::~socketbsd()

				{

					delete p_addr_st;

				}


	} // namespace so
