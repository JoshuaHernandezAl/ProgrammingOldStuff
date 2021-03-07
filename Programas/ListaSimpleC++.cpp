#include <conio.h>
#include <iostream>
#include  <stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *sgte;
};
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarLista(Nodo *&,int);
void eliminarTodo(Nodo *&, int &);
void menu();
Nodo *lista=NULL;
int main(){
	menu();
	getch();
	return 0;
}
void menu(){
	int op,dato;
	do{
		cout<<"Menu bien chido"<<endl;
		cout<<"1.- Insertar"<<endl;
		cout<<"2.- Mostrar"<<endl;
		cout<<"3.- Buscar"<<endl;
		cout<<"4.- Eliminar"<<endl;
		cout<<"5.- Eliminar todo/Vaciar Lista"<<endl;
		cout<<"6.-Salir"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		switch(op){
			case 1: 
				cout<<"\nInserte un numero: ";
				cin>>dato;
				insertarLista(lista,dato);
				system("pause");
			break;
			case 2:
				mostrarLista(lista);
				cout<<endl;	
				system("pause");
			break;
			case 3:
				cout<<"Numero de busqueda: ";
				cin>>dato;
				buscarLista(lista,dato);
				cout<<endl;
				system("pause");
			break;
			case 4:
				cout<<"Digito a borrar: ";
				cin>>dato;
				eliminarLista(lista, dato);
				cout<<endl;
				system("pause");
			break;
			case 5:
				while(lista!=NULL){
					eliminarTodo(lista,dato);
					cout<<dato<<" -> ";
				}
				cout<<endl;
				system("pause");
			break;
			case 6:
				exit(0);
			break;
		}
		system("cls");
	}while(op!=6);
}
void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	
	Nodo *aux1=lista;
	Nodo *aux2;
	
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->sgte;	
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}
	else{
		aux2->sgte=nuevo_nodo;
		
	}
	
	nuevo_nodo->sgte=aux1;
	
	cout<<"Elemento "<<n<<" insertado correctamente :D"<<endl;
}
void mostrarLista(Nodo *lista){
	Nodo *actual=new Nodo();
	actual=lista;
	while(actual!=NULL){
		cout<<actual->dato<<" ->";
		actual=actual->sgte;
	}
}
void buscarLista(Nodo *lista, int n){
	bool band=false;
	Nodo *actual=new Nodo();
	actual=lista;
	while((actual!=NULL)&&(actual->dato<=n)){
		if(actual->dato==n)
			band=true;
		actual=actual->sgte;
	}
	if(band==true){
		cout<<"Elememto "<<n<<" es parte de la lista"<<endl;
	}
	else{
		cout<<"Elememto "<<n<<" no es parte de la lista"<<endl;
	}
}
void eliminarLista(Nodo *&lista, int n){
	if(lista!=NULL){
		Nodo*aux_borrar;
		Nodo *anterior=NULL;
		aux_borrar=lista;
		while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->sgte;
		}
		if(aux_borrar==NULL){
			cout<<"ELemento no encontrado"<<endl;
		}
		else if(anterior==NULL){
			lista=lista->sgte;
			delete aux_borrar;
		}
		else{
			anterior->sgte=aux_borrar->sgte;
			delete aux_borrar;
		}
		
	}
}
void eliminarTodo(Nodo *&lista,int &n){
	Nodo *aux=lista;
	n=aux->dato;
	lista=aux->sgte;
	delete aux;
}
