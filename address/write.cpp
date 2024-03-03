// write.cpp - реализация методов класса SocketAddressBSD для записи данных в структуру адреса сокета


#include <cerrno>

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Запись ip-адреса сокета в структуру адреса сокета

			unsigned int sockaddrbsd::writeIp(const char *ipaddr)

				{

					void *p_ipaddr;

					int family = addr->sa_family;


					switch(family) { // Инициализация указателя ня структуру ip-адреса сокета


						// Инициализация указателя на структуру ip-адреса сокета IPv4

							case AF_INET: 
									
									// Инициализация указателя на структуру ip-адреса сокета

        			         		p_ipaddr = &addr4.sin_addr;

									// Запись ip-адерса сокета в структуру ip-адреса сокета

										if(*ipaddr == 0)
										
											{
		
												addr4.sin_addr.s_addr = INADDR_ANY;

												return 0;

											}

									break;


						// Инициализация указателя на структуру ip-адреса сокета IPv6

							case AF_INET6: p_ipaddr =  &addr6.sin6_addr; break;
							
							
						// Инициализация указателя на структуру ip-адреса по умолчанию
						
							default: p_ipaddr = &addr4.sin_addr;


					} // switch(family)

				

					// Преобразование сетевого адреса из строки в числовое представление, запись его
					// в структуру ip-адреса сокета, а также возврат статуса завершения операции 

        	      	if(inet_pton(family, ipaddr, p_ipaddr) < 0) return errno;
        	      	
        	      	
        	      return 0;    


				} // unsigned int writeIp(const char *ipaddr)



			// Запись порта сокета в структуру адреса сокета

				void sockaddrbsd::writePort(unsigned int port)

					{

						int family = addr->sa_family;


						// Запись порта в структуру адреса сокета в зависимости от семейсва пртоколов сокета

							switch(family) {


								// Запись порта в структуру ip-адреса сокета IPv4

									case AF_INET: addr4.sin_port = htons(port); break;

								// Запись порта в структуру ip-адреса сокета IPv6

									case AF_INET6: addr6.sin6_port = htons(port); break;
									
								// Запись порта по умолчанию
								
									default: addr4.sin_port = htons(port);
											

							} // switch(family) 


					} // void writePort(unsigned int port)

						
	} // namespace so
