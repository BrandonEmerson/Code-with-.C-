cliente: cliente.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ cliente.cpp PaqueteDatagrama.o SocketDatagrama.o -o cliente
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
