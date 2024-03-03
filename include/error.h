// error.h - описание класса для обработки исключений, которые возникает при работе с классом SocketErrorBSD


#include <string>


#ifndef SOCKET_ERROR_BSD_H_
#define SOCKET_ERROR_BSD_H_


	namespace so {	// Пространсво имён сокетов

		
		using std::string;


		class sockerrbsd {


			private:


				int errnum;          // Номер ошибки

				const char *errstr;	// Строка с текстом ошибки

				string class_name;	// Строка с именем класса, в котором произошла ошибка

				string method_name;	// Строка с именем метода класса, в котором произошла ошибка

				
				const char *initErrorString(void); // Метод для инициализации строки с текстом ошибки


			public:


				// Конструкторы и деструкторы класса


					// Конструктор класса по умолчанию

						sockerrbsd();

					// Пользовательский конструктор класса

						sockerrbsd(int errnum_, const string & class_name_, const string & method_name_);

					// Деструктор по умолчанию

						virtual ~sockerrbsd() {}


				// Методы для получения значений закрытых членов класса


					// Получение номера ошибки

						int geterrnum() const;

					// Получение строки с текстом ошибки

						const char *geterrstr(void) const;

					// Получение строки с именем класса, в котором произошла ошибка

						const string & getclassname() const;
					
					// Получение строки с именем метода класса, в котором произошла ошибка

						const string & getmethodname() const;


				// Методы для установки значений закрытых членов класса

					
					// Установка номера ошибки

						void seterrnum(int errnum_);

					// Установка строки с именем класса, в котором произошла ошибка

						void setclassname(const string & class_name_);

					// Установка строки с именем метода, в котором произошла ошибка

						void setmethodname(const string & method_name_);

					// Установка значений всех закрытых членов класса и строки с текстом ошибки

						void seterrstr(int errnum_, const string & class_name_, const string & method_name_);


				// Выод сообщения об ошибке в стандартный поток вывода

					void showmesg(void);


		}; // sockerrbsd


	} // namespace SO


#endif // SOCKET_ERROR_BSD_H_
