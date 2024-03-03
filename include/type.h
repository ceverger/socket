// type.h - описание классов для задания свойств сокета


#ifndef SOCKET_TYPE_H_
#define SOCKET_TYPE_H_


	// Описание макроса с начальным или неизвестным значением

		#define UNKNOW_VALUE -1   

	// Описание макроса с максимальной длиной адреса сокета

      #define SOCKET_ADDRESS_MAX_LEN 128

	// Описание макроса с максимальным количеством соединений, которое сокет может присоединить

		#define SOCKET_CONNECTIONS_MAX_COUNT 10 


	namespace so { // Пространство имен сокетов


		// Класс для идентификации состояния сокета

			class status { public: enum { closed, opened, connected, listened }; };


	} // namespace so


#endif // SOCKET_TYPE_H_
