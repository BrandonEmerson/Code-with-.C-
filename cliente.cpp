#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	SocketDatagrama c(0);
	string ip;
	cout << "Ingrese la direccion:" << endl;
	cin >> ip;
 	int num[2];
	num[0]=5;
	num[1]=2;
	PaqueteDatagrama solicitud((char*)num,2*sizeof(int),(char *)ip.c_str(),7200), respuesta(4);
	c.envia(solicitud);
	cout <<"5+2="<<c.recibe(respuesta)<< endl ;
}