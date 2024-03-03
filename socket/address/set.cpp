// set.cpp - реализация методов установки значений закрытых членов класса SocketAddressBSD


#include <cerrno>

#include "error.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Инициализация семейства протоколов структуы адреса сокета в зависимости от семейства протоколов сокета

			void sockaddrbsd::setaddr(int family)

				{

					// Инициализация семейства протоколов, укзателя на
					// универсальную структуру адреса сокета и ее размера

						switch(family) { 


							case AF_INET: 

								addr = (struct sockaddr *) &addr4;

								addr4.sin_family = family;

								size_addr = sizeof(addr4); 

								break;


							case AF_INET6: 

								addr = (struct sockaddr *) &addr6; 

								addr6.sin6_family = family;

								size_addr = sizeof(addr6); 

								break;


					} // switch(family)


				} // void setfamily(int family)

						
	} // namespace so
