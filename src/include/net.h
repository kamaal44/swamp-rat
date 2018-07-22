/*-----------------------------------------------------------------------\
| Copyright (C) 2018  Lilly Chalupowski                                  |
|                                                                        |
| This program is free software: you can redistribute it and/or modify   |
| it under the terms of the GNU General Public License as published by   |
| the Free Software Foundation, either version 3 of the License, or      |
| (at your option) any later version.                                    |
|                                                                        |
| This program is distributed in the hope that it will be useful,        |
| but WITHOUT ANY WARRANTY; without even the implied warranty of         |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          |
| GNU General Public License for more details.                           |
|                                                                        |
| You should have received a copy of the GNU General Public License      |
| along with this program.  If not, see <https://www.gnu.org/licenses/>. |
\-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdbool.h>

bool net_host2ip(char *host, char* ip, size_t ip_size){
  /*
    :TODO: host to ip
    :host: host domain
    :ip: pointer to ip
    :returns: ip address
  */
  struct hostent *he;
  struct in_addr **addr_list;
  int i;
  if ((he = gethostbyname(host)) == NULL){
    herror("gethostbyname");
    return false;
  }
  addr_list = (struct in_addr **) he->h_addr_list;
  for(i = 0; addr_list[i] != NULL; i++){
    strncpy(ip , inet_ntoa(*addr_list[i]), ip_size);
    return true;
  }
  return false;
}
