#include <stdio.h>
#include <time.h>
#include "E101.h"

// loads specific methods from ENGR101 library, not sure if this is even needed
//extern "C" int init(int d_lev);
//extern "C" int connect_to_server(char server_addr[15],int port);
//extern "C" int send_to_server(char message[24]);
//extern "C" int receive_from_server(char message[24]);


int main(){
	init();//not sure about this lineeee
	char message[24];
	char server_address[] = "130.195.6.196";
	char pls[] = "Please";
	connect_to_server(server_address, 1024);
	send_to_server(pls);
	receive_from_server(message);//could be buggy, test it
	send_to_server(message);
	
	sleep1(1,0);
	
	
return 0;}



	
	
	
	
	
