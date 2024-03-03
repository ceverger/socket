// init.cpp - реализация методов класса socketbsd для инициализации некоторых параметров сокета, таких как семейство протоколов,
//				  тип и протокола передачи данных, а также универсальной структуры адреса сокета и закрытых членов класса socketbsd


#include "error.h"

#include <cstring>

#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имен сокетов

    
   	// Подбор семейсва протоколов сокета по идентификатору семейства протоколов сокета

			int socketbsd::familyInit(int id) 

         	{

             	switch(id) {

                	case domain::ipv4_id:  return AF_INET;

                  case domain::ipv6_id:  return AF_INET6;

                  case domain::local_id: return AF_LOCAL;

                  case domain::route_id: return AF_ROUTE;

                  case domain::key_id:   return AF_KEY;

                  default:               return UNKNOW_VALUE;

					}

				}


		// Подбор типа сокета по идентификатору типа сокета

			int socketbsd::typeInit(int id)

				{
                  
            	switch(id) {

               	case sort::stream_id: return SOCK_STREAM;

                  case sort::dgram_id:  return SOCK_DGRAM;

                  case sort::packet_id: return SOCK_SEQPACKET;

                  case sort::raw_id:    return SOCK_RAW;

                  default:              return UNKNOW_VALUE;

					}                 
                
				}


		// Подбор протокола сокета по идентификатору протокола сокета

			int socketbsd::protocolInit(int id)

         	{

            	switch(id) {

               	case transfer::tcp_id:  return IPPROTO_TCP;

                  case transfer::udp_id:  return IPPROTO_UDP;

                  case transfer::sctp_id: return IPPROTO_SCTP;

                  default:                return UNKNOW_VALUE;

               } 
                
				}


		// Инициализация закрытых членов класса значениями из структуры адреса сокета

			void socketbsd::dataInit(void)

				{
				
					try { // Блок обработки исключений
					
					
						// Чтение ip-адреса из структуры адреса сокета и генерация исключения в случае неудачи
						
							int errnum = p_addr_st->readIp(ipaddr, SOCKET_ADDRESS_MAX_LEN);

							if(errnum > 0) 
							
								throw(errnum, "sockaddrbsd", 
								
									"unsigned int readIp(char *, unsigned int) const");
									
									
						// Чтение порта из структуры адреса сокета
									
							port = p_addr_st->readPort();
							
									
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключений 
					
						{ 
					
							excep.showmesg();
					
						}
					

				} // void dataInit(void)
				
				
			
		// Инициализация структуры адреса сокета значениями закрытых членов класса

			void socketbsd::addrInit(void)
			
				{
				
				
					try { // Блок отслеживания исключений
					
						
						// Номер ошибки
						
							int errnum;
							
							
						// Инициализация указателя на универсальную структуру адреса сокета  
				
							p_addr_st->setaddr(family);
							
							
						// Запись ip-адреса в структуру адреса сокета и генерация исключени в случае неудачи
					
							if((errnum = p_addr_st->writeIp(ipaddr)) > 0)
							
								throw sockerrbsd(errnum, "sockaddrbsd", "unsigned int writeIp(const char *)");
								
								
						// Запись порта в структуру адреса сокета
					
							p_addr_st->writePort(port); 
						
							
					} // try
					
					
					catch(sockerrbsd & excep) // Обработка исключений
					
						{
						
							excep.showmesg();
						
						}
				
				
				} // void addrInit(void)


	}	// namespace so
