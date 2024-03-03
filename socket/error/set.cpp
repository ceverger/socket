// set.cpp - рализация методов для получения значений закрытых членов класса SocketErrorBSD


#include "error.h"


	namespace so {	// Пространсво имён сокетов
	

		// Установка номера ошибки

			void sockerrbsd::seterrnum(int errnum_)

				{

					errnum = errnum_;

					errstr = initErrorString();

				}


		// Установка строки с именем класса, в котором произошла ошибка

			void sockerrbsd::setclassname(const string & class_name_)

				{

					class_name = class_name_;

				}


		// Установка строки с именем метода класса, в котором произошла ошибка

			void sockerrbsd::setmethodname(const string & method_name_)

				{

					method_name = method_name_;

				}


		// Установка значений всех закрытых членов класса и строки с текстом ошибки

			void sockerrbsd::seterrstr(int errnum_, const string & class_name_, const string & method_name_)

				{

					errnum = errnum_;

					errstr = initErrorString();

					class_name = class_name_;

					method_name = method_name_;

				}


	}; // namespace so
