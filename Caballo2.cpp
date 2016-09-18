#include "Jugada.hpp"
#include "includes.hpp"
using namespace std;
using namespace Caballeo;
struct Elemento{
	Jugada *jugada;
	Elemento *sig;
};
typedef Elemento* Lista;
void iniTablero(Tablero &t){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			t[i][j]=65;
		}
	}
}
void dibTablero(Tablero &t){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout<<setw(2)<<t[j][i];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int size(Lista &lista){
	Lista ptr=lista;
	int res=0;
	while(ptr!=nullptr){
		res++;
		ptr=ptr->sig;
	}
	return res;
}

int main(){
	Tablero t;
	iniTablero(t);dibTablero(t);
	Lista lista=new Elemento;
	lista->sig=nullptr;
	lista->jugada=new Jugada(t, 0,0, 0);
	t[0][0]=1;
	while(size(lista)<64){
		Lista ptr=lista;
		while(ptr->sig!=nullptr){
			ptr=ptr->sig;
		}
		//if(a>=60){
			//cout<<"turno "<<ptr->jugada->getTurno()+1<<endl;
		//		dibTablero(t);
		//	}
		if(ptr->jugada->hayOpt()){
			int n=size(lista);
			ptr->sig=new Elemento;
			//ptr->jugada->recorrerLista();
			//cout<<"hpene"<<endl;
			t[ptr->jugada->sigMovY()][ptr->jugada->sigMovX()]=n+1;
			ptr->sig->sig=nullptr;
			ptr->sig->jugada=new Jugada(t,ptr->jugada->sigMovX(),ptr->jugada->sigMovY(), n);
			
		}else{
			Lista ptr2=lista;
			//cout<<"borrar"<<endl;
			while(ptr2->sig->sig!=nullptr){
				ptr2=ptr2->sig;
			}
			t[ptr2->jugada->sigMovY()][ptr2->jugada->sigMovX()]=65;
			ptr2->jugada->eliminarOpt();
			delete ptr2->sig;
			ptr2->sig=nullptr;
		}

	}
	dibTablero(t);
}