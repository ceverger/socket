// get.cpp - реализация методов получения значений закрытых членов класса socketbsd


#include <cerrno>

#include <cstring>

#include "socket.h"

#include "address.h"


	namespace so { // Пространсво имён сокетов

    
   	// Получение идентификатора состояня сокета

			int socketbsd::getstate(void) const

         	{

            	return state;                
                
         	}



		// Получение идентификатора семейства сокета

      	int socketbsd::getfamily(void) const

         	{

            	switch(family) {

               	case AF_INET:	return domain::ipv4_id;

                  case AF_INET6: return domain::ipv6_id;

                  case AF_LOCAL: return domain::local_id;

                  case AF_ROUTE: return domain::route_id;

                  case AF_KEY:   return domain::key_id;

                  default:   		return UNKNOW_VALUE;

					}

				}



		// Получение идентификатора типа сокета

      	int socketbsd::gettype(void) const

         	{

            	switch(type) {

               	case SOCK_STREAM:    return sort::stream_id;

                  case SOCK_DGRAM:     return sort::dgram_id;

                  case SOCK_SEQPACKET: return sort::packet_id;

                  case SOCK_RAW:       return sort::raw_id;

                  default:             return UNKNOW_VALUE;

            	} 
                
            }



		// Получение идентификатора пртокола сокета

			int socketbsd::getprotocol(void) const

				{

					switch(protocol) {

               	case IPPROTO_TCP:  return transfer::tcp_id;

                  case IPPROTO_UDP:  return transfer::udp_id;

                  case IPPROTO_SCTP: return transfer::sctp_id;

                  default:           return UNKNOW_VALUE;

					}
                
				}



		// Послучение строки ip-адреса сокета

			const char *socketbsd::getipaddr(void) const

         	{
                
					return ipaddr;
                
         	}



		// Получение номера порта сокета

			int socketbsd::getport(void) const

                {

                    return port;                
                
                }


    } // namespace so
