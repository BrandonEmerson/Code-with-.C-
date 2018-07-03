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
	unsigned int n;
	n=4294967291;
	string ip = "10.100.65.224",ip2 = "10.100.68.62", ip3 = "10.100.71.66";
 	unsigned int num[3];
	num[0]=2;
	num[1]=(n/8);
	num[2]=n;
	PaqueteDatagrama solicitud((char*)num,3*sizeof(int),(char *)ip.c_str(),7200), respuesta(4);
	c.envia(solicitud);
	num[0]=(n/8)+1;
	num[1]=(n/8)*2;
	PaqueteDatagrama solicitud2((char*)num,3*sizeof(int),(char *)ip.c_str(),7201);
	c.envia(solicitud2);
	num[0]=(n/8)*2+1;
	num[1]=(n/8)*3;
	PaqueteDatagrama solicitud3((char*)num,3*sizeof(int),(char *)ip.c_str(),7202);
	c.envia(solicitud3);
	num[0]=(n/8)*3+1;
	num[1]=(n/8)*4;
	PaqueteDatagrama solicitud4((char*)num,3*sizeof(int),(char *)ip2.c_str(),7200);
	c.envia(solicitud4);
	num[0]=(n/8)*4+1;
	num[1]=(n/8)*5;
	PaqueteDatagrama solicitud5((char*)num,3*sizeof(int),(char *)ip3.c_str(),7200);
	c.envia(solicitud5);
	num[0]=(n/8)*5+1;
	num[1]=(n/8)*6;
	PaqueteDatagrama solicitud6((char*)num,3*sizeof(int),(char *)ip3.c_str(),7201);
	c.envia(solicitud6);
	num[0]=(n/8)*6+1;
	num[1]=(n/8)*7;
	PaqueteDatagrama solicitud7((char*)num,3*sizeof(int),(char *)ip3.c_str(),7202);
	c.envia(solicitud7);
	num[0]=(n/8)*7+1;
	num[1]=n;
	PaqueteDatagrama solicitud8((char*)num,3*sizeof(int),(char *)ip3.c_str(),7203);
	c.envia(solicitud8);
	int s=0;
	while(s!=8){
	if(c.recibe(respuesta)==1){
		cout << "No es primo" << endl;
		exit(0);	
	}else{
	s++;
	}
}
	cout << "Es primo" << endl;
}