// show.cpp - реализация метода вывода сообщения об ошибке в стандартный поток ввода вывода


#include "error.h"

#include <iostream>


	namespace so { // Пространство имен сокетов
	

		void sockerrbsd::showmesg(void)

			{

				std::cout << "Исключение! " 
				
							 << "Класс: " << class_name << "; "
							 
							 << "Метод: " << method_name << "; "
							 
							 << "Ошибка: " << errstr << ";"
							 
							 << std::endl;

			} // void showmesg(void)


	} // namespace so
