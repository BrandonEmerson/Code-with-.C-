#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

SocketDatagrama::SocketDatagrama(int p){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(p);
   	bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

int SocketDatagrama::recibe(PaqueteDatagrama & p){
	int res;
	char recv[16];
	int r = recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
	p.inicializaDatos((char *)&res);
	inet_ntop(AF_INET,&direccionForanea.sin_addr,recv,sizeof(recv));
	cout <<"Recibo de " << recv << " Port: " <<ntohs(direccionForanea.sin_port) << endl;
	return res;
}

int SocketDatagrama::envia(PaqueteDatagrama & p){
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}