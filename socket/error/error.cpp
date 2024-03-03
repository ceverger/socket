// error.cpp - реализация конструкторов класса SocketErrorBSD


#include "error.h"


	namespace so { // Пространсво имен сокетов


		// Констуктор класса по умолчанию

			sockerrbsd::sockerrbsd()

				{

					errnum = -1;

					errstr = initErrorString();

				}


		// Пользовательский конструктор класса

			sockerrbsd::sockerrbsd(int errnum_, const string & class_name_, const string & method_name_)

				{

					errnum = errnum_;

					errstr = initErrorString();

					class_name = class_name_;

					method_name = method_name_;

				}
			

	} // namespace so
