// address.cpp - реализация конструкторов и деструкторов объектов класса SocketAddressBSD


#include <cstring>

#include "address.h"


	namespace so { // Пространсво имён сокетов


		// Конструктор класса по умолчанию

			sockaddrbsd::sockaddrbsd()

				{

					addr = 0;

					size_addr = 0;

					bzero(&addr4, sizeof(addr4));

					bzero(&addr6, sizeof(addr6));

				}


		// Пользовательский конструктор класса

			sockaddrbsd::sockaddrbsd(int family)

				{

					addr = 0;

					size_addr = 0;

					bzero(&addr4, sizeof(addr4));

					bzero(&addr6, sizeof(addr6));


					setaddr(family);


				} // sockaddrbsd(int family_)


	} // namespace so
			
