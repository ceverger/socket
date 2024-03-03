#ifndef SOCKET_ERROR_DATA_BSD_H_
#define SOCKET_ERROR_DATA_BSD_H_


	// Структура, содержащая номер ошибки и соответсвующую этому номеру строку

   	struct strtab { const int number; const char *string; }

      	errtab[] = { //Таблица соответсвия строк ошибок их целочисленным идентификаторам

				{ -1, "ошибки отсутствуют" },

				{ -2, "для выполнения данной операции сокет должен находиться в закрытом состоянии"},

            { -3, "для выполнения данной операции сокет должен находиться либо закрытом, либо в открытом состоянии" },

            { -4, "для выполнения данной операции сокет должен находиться в открытом состоянии"},
		
	         { -5, "для выполнения данной операции сокет должен находиться состоянии соединения"},
									 
	         { -6, "для выполнения данной операции сокет должен находиться состоянии прослушивания"},
	
	         { -7, "для выполнения данной операции необходимо корректно инициализировать семейство протоколов сокета" },
	
	         { -8, "для выполнения данной операции необходимо корректно инициализировать семейство протоколов удаленного сокета" },
	
	         { -8, "для выполнения данной операции необходимо корректно инициализировать семейство протоколов присоединямого сокета" },
	
	         { -9, "невозможно изменить значение ip-адреса сокета, так как стурктура адреса" },
	
	         { -10, "невозможно изменить значение порт сокета, так как стурктура адреса" },
	
	         { -11, "универсальная структура адреса сокета не инициализированна" },
	
	         { -12, "универсальная структура адреса сокета инициализированна некорректно" },
	
	         { -13, "невозможно изменить параметр сокета, так как сокет уже участвует в соединении" },
	
	         { -14, "количество прослушиваемых соединений для сервера не может быть равно нулю" },
	
	         { -15, "невозможно соединиться с заданным удаленным сокетом, так как уже установлено соединение с другим удалённым сокетом" },     
	
	         { -16, "невозможно установить данный статус сокета, так как сокет уже является прослушиваемым" }, 
	
	         { -17, "для установки данного статуса, сокет должен быть открыт" },
	
	         { -18, "некорректно задана роль сокета" },
	
	         { -19, "невозможно назначить ip-адрес и порт, так как сокет не находится в открытом состоянии" },
	
	      	{ -20, "невозможно сделать сокет прослушиваемым, так как сокет не является сервером" },

	         { -21, "невозможно присоединить сокет, так как серверный сокет не является прослушиваемым" },

	         { -22, "невозможно присоединить сокет, так как сокет уже участвует в другом соединении" },

	         { -23, "невозможно соединиться с удаленным сокетом, так как отсутвует указатель на объект данных удаленного сокета" },

	         { -24, "невозможно присоединить сокет, так как отсутвует указатель на объект данных серверного сокета" },

	         { -25, "невозможно запустить сервер, так как сервер уже запущен" },

	         { -26, "невозможно получить соединение, так как сервер не запущен" },

	         { -27, "невозможно прочитать данные из сокета, так как сокет не учавствует в сетевом соединении" },

	         { -28, "невозможно прочитать данные из сокета, так как отсутвует буфер для сохранения прочитанной информации" },

	         { -29, "размер буфер для сохранения прочитанной информации не может быть равен нулю" },

	         { -30, "невозможно записать данные в сокет, так как сокет не учавствует в сетевом соединении" },

	         { -31, "невозможно записать данные в сокет, так как отсутвует буфер с данными для записи" },

	         { -32, "размер буфер c данными для записи не может быть равен нулю" },

				{   0, "ошибка не найдена"	}

						};


#endif // SOCKET_ERROR_DATA_BSD_H_