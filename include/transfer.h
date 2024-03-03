// transfer.h - описания классов для идентификации протоколов передачи данных сокета


#ifndef TRANSFER_H_
#define TRANSFER_H_


	namespace so { // Протсранство имен сокетов


		// Абстрактный класс для идентификации типа сокета

			class transfer {


				private:


					// Идентификатор семейсва протокола сокета
							
						int id; 


				public:
		
					
					// Перечисляемый тип, который хранит константы, идентифицирующие все возможные протоколы сокета
		
						enum { tcp_id, udp_id, sctp_id };


					// Конструктор класса по умолчанию

						transfer() { id = UNKNOW_VALUE; }
						
					// Деструктор класса по умолчанию

						virtual ~transfer() {}


					// Получение идентификатора номера протокола

						int getid() const { return id; }

					// Установка идентификатора типа сокета

						void setid(int id_) { id = id_; }


			}; // transfer


		// Класс для идентификации протокола tcp

			class tcp : public transfer { 


				public: 


					// Конструкторы и деструкторы класса

		
						// Конструктор по умолчанию

							tcp() { setid(tcp_id); }
						

						// Деструктор по умолчанию

							virtual ~tcp() {}
				

			}; // tcp



		// Класс для идентификации протокола udp

			class udp : public transfer{ 


				public: 


					// Конструкторы и деструкторы класса

		
						// Конструктор по умолчанию

							udp() { setid(udp_id); }

						// Деструктор по умолчанию

							virtual ~udp() {}
				

			}; // udp


		// Класс для идентификации ппротокла stcp

			class sctp : public transfer { 


				public: 


					// Конструкторы и деструкторы класса

		
						// Конструктор по умолчанию

							sctp() { setid(sctp_id); }

						// Деструктор по умолчанию

							virtual ~sctp() {}
				

			}; // sctp
			
			
		// Статический объект класса идентификатора номера протокола tcp
		
			static tcp tcp;
			
		// Статический объект класса идентификатора номера протокола udp
		
			static udp udp;
			
		// Статический объект класса идентификатора номера протокола stcp
		
			static sctp sctp;
		

	} // namespace so


#endif // TRANSFER_H_
