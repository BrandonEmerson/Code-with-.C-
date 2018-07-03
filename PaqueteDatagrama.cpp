#include "PaqueteDatagrama.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *d, unsigned int t, char *i, int p){
	datos = new char[t];
	memcpy(datos,d,t);
	strcpy(ip,i);
	puerto = p;
	longitud=t;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int t){
	datos = new char[t];
}

char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto=p;
}

void PaqueteDatagrama::inicializaIp(char *i){
	strcpy(ip,i);
}

void PaqueteDatagrama::inicializaDatos(char *d){
	memcpy(datos,d,longitud);
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete[] datos;
}
