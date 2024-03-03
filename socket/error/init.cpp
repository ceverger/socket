// init.cpp - реализация закрытых методов инициализации значений закрытых членов класса


#include "data.h"

#include <cerrno>

#include "error.h"

#include <cstring>


	namespace so { // Пространство имен сокетов


		// Инициализация строки с текстом ошибки

			const char *sockerrbsd::initErrorString()

				{

					// Максимальное количество строк с ошибками

						int max = 0;

					// Подсчет максимального количества строк с ошибками

						while(errtab[max++].number != 0);

					
					// Возврат строки ошибки, если номер ошибки был сохранен в переменно errno

    					if(errnum > 0) return strerror(errnum);

					
					// Поиск строк ошибки в таблице ошибок

    					for(int i = 0; i < max; ++i)

    						if(errtab[i].number == errnum) return errtab[i].string;


					// Возврат сообщения о том, что ошибка не была найдена        

        				return errtab[max - 1].string;


				} // const char *initErrorString()
						

	} // namespace so
