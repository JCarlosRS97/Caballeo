#ifndef __Jugada__
#define __Jugada__
#include "includes.hpp"
namespace Caballeo {
class Jugada {
public:
	Jugada(Tablero &t, int x, int y, int numeroTurno);
	int getX();
	int getY();
	int getTurno();
	int sigMovX();
	int sigMovY();
	void eliminarOpt();
	bool hayOpt();
	void recorrerLista();
private:
	void insertar(int x, int y);
private:
	struct Nodo
	{
		int x, y;
		Nodo *sig;
	};
	typedef Nodo* Lista;
	Lista lista;
	int x, y, nTurno;

};
}
#endif