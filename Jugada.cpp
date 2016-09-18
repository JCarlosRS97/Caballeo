#include "Jugada.hpp"
using namespace std;
using namespace Caballeo;
Jugada::Jugada(Tablero &t, int x, int y, int nTurno){
	this->x=x;
	this->y=y;
	this->nTurno=nTurno;
	lista=nullptr;
	if(x+1<8 && y+2<8 && t[y+2][x+1]>nTurno){
//		cout<<"opcion 1"<<endl;
		insertar(x+1, y+2);
	}
	if(x+2<8 && y+1<8 && t[y+1][x+2]>nTurno){
//		cout<<"opcion 2"<<endl;
		insertar(x+2, y+1);
	}
	if(x+2<8 && y-1>=0 && t[y-1][x+2]>nTurno){
		insertar(x+2, y-1);
//		cout<<"opcion 3"<<endl;
	}
	if(x+1<8 && y-2>=0 && t[y-2][x+1]>nTurno){
		insertar(x+1, y-2);
//		cout<<"opcion 4"<<endl;
	}
	if(x-1>=0 && y-2>=0 && t[y-2][x-1]>nTurno){
		insertar(x-1, y-2);
//		cout<<"opcion 5"<<endl;
	}
	if(x-2>=0 && y-1>=0 && t[y-1][x-2]>nTurno){
		insertar(x-2, y-1);
//		cout<<"opcion 6"<<endl;
	}
	if(x-2>=0 && y+1<8 && t[y+1][x-2]>nTurno){
		insertar(x-2, y+1);
//		cout<<"opcion 7"<<endl;
	}
	if(x-1>=0 && y+2<8 &&  t[y+2][x-1]>nTurno){
		insertar(x-1, y+2);
//		cout<<"opcion 8"<<endl;
	}

}
void Jugada::insertar(int x, int y){
	Lista ptr=lista;
	lista= new Nodo;
	lista->x=x;
	lista->y=y;
	lista->sig=ptr;
}
int Jugada::getX(){
	return x;
}
int Jugada::getY(){
	return y;
}
int Jugada::sigMovX(){
	return lista->x;
}
int Jugada::sigMovY(){
	return lista->y;
}
void Jugada::eliminarOpt(){
	Lista ptr=lista;
	lista=lista->sig;
	delete ptr;
}
int Jugada::getTurno(){
	return nTurno;
}
bool Jugada::hayOpt(){
	return lista!=nullptr;
}
void Jugada::recorrerLista(){
	Lista ptr=lista;
	while(ptr!=nullptr){
		cout<<ptr->x<<" "<<ptr->y<<endl;
		ptr=ptr->sig;
	}
}