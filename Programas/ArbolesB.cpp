#include <stdlib.h>
#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;	
	Nodo *izq;
	Nodo *padre;
};

Nodo *arbol=NULL;

Nodo *crearNodo(int, Nodo *);
void insertar(Nodo *&, int , Nodo *);
void mostrarArbol(Nodo *, int);
bool buscarNodo(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminarNodo(Nodo *,int);
void eliminar(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruir(Nodo *);
void menu();

int main(){
	menu();
	return 0;
}
void menu(){
	int dato, op,contador=0;
	do{
		cout<<"Menu"<<endl;
		cout<<"1.-Nuevo nodo"<<endl;
		cout<<"2.- Mostrar Arbol"<<endl;
		cout<<"3.- Buscar Nodo"<<endl;
		cout<<"4.-PreOrden"<<endl;
		cout<<"5.-InOrden"<<endl;
		cout<<"6.-PostOrden"<<endl;
		cout<<"7.-Eliminar Nodo"<<endl;
		cout<<"8.-Salir"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		switch(op){
			case 1:
				cout<<"Digite un numero: ";
				cin>>dato;
				insertar(arbol,dato,NULL);
				cout<<endl;
				system("pause");
			break;
			case 2:
				mostrarArbol(arbol,contador);
				cout<<endl;
				system("pause");
			break;
			case 3:
				cout<<"Digite un dato: ";
				cin>>dato;
				if(buscarNodo(arbol, dato)==true){
					cout<<"Elemento "<<dato<<" parte del arbol";
				}
				else{
					cout<<"Elemento "<<dato<< " no es parte del arbol";
				}
				cout<<endl;
				system("pause");
			break;
			case 4:
				preOrden(arbol);
				cout<<endl;
				system("pause");
			break;
			case 5:
				inOrden(arbol);
				cout<<endl;
				system("pause");
			break;
			case 6:
				postOrden(arbol);
				cout<<endl;
				system("pause");
			break;
			case 7:
				cout<<"Digite el Nodo: ";
				cin>>dato;
				eliminarNodo(arbol,dato);
				cout<<endl;
				system("pause");
			break;
			case 8:
				exit(0);
			break;
		}
		system("cls");
	}while(op!=8);
}
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre;
	return nuevo_nodo;
}
void insertar(Nodo *&arbol, int n, Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n, padre);
		arbol=nuevo_nodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertar(arbol->izq,n, arbol);
		}
		else{
			insertar(arbol->der,n, arbol);
		}
	}
}
void mostrarArbol(Nodo *arbol, int contador){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, contador+1);
		for(int i=0;i<contador;i++){
			cout<<"	";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,contador+1);
	}
}
bool buscarNodo(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else if(n<arbol->dato){
		return buscarNodo(arbol->izq,n);
	}
	else{
		return buscarNodo(arbol->der,n);
	}
	
}
void preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}
void inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}
void postOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
		
	}
}
void eliminarNodo(Nodo *arbol,int n){
	if(arbol==NULL)	{
		return;
	}
	else if(n<arbol->dato){
		eliminarNodo(arbol->izq,n);
	}
	else if(n>arbol->dato){
		eliminarNodo(arbol->der,n);
	}
	else{
		eliminar(arbol);
	}
}
void eliminar(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminar(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruir(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL);
		destruir(nodoEliminar);
	}
}
Nodo *minimo(Nodo *arbol){
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}
void reemplazar(Nodo *arbol, Nodo *nuevo_nodo){
	if(arbol->padre){
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq=nuevo_nodo;
		}
		else if(arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevo_nodo;
		}
	}
	if(nuevo_nodo){
		nuevo_nodo->padre=arbol->padre;
	}
}
void destruir(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}
