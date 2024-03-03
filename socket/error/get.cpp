// get.cpp - рализация методов для получения значений закрытых членов класса SocketErrorBSD


#include "error.h" 


	namespace so { // Пространсво имён сокетов


		// Получение номера ошибки

			int sockerrbsd::geterrnum() const
	
				{

					return errnum;

				}

			
		// Получение строки с текстом ошибки

			const char *sockerrbsd::geterrstr(void) const

				{

					return errstr;

				}


		// Получение строки с именем класса, в котором произошла ошибки

			const string & sockerrbsd::getclassname() const

				{

					return class_name;

				}


		// Получение строки с именем метода класса, в котором произошла ошибка

			const string & sockerrbsd::getmethodname() const

				{

					return method_name;

				}


	} // namespace SO
