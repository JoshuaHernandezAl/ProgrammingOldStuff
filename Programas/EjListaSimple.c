#include <stdio.h>
#include <stdlib.h>
typedef struct{
	float dato;
	struct Nodo *sgte;
}Nodo;

Nodo *primer=NULL;
Nodo *ultimo=NULL;

void agregar(Nodo *nodo){
	nodo->sgte=NULL;
	if(primer==NULL){
		primer=nodo;
		ultimo=nodo;
	}
	else{
		ultimo->sgte=nodo;
		ultimo=nodo;
	}
}
int main(){
	float n1,n2,n3;
	printf("INgresa tres numeros flotantes: ");
	scanf("%f,%f,%f",&n1,&n2,&n3);
	Nodo *primerNodo=malloc(sizeof(Nodo));
	primerNodo->dato=n1;
	Nodo *segundoNodo=malloc(sizeof(Nodo));
	segundoNodo->dato=n2;
	Nodo *tercerNodo=malloc(sizeof(Nodo));
	tercerNodo->dato=n3;
	agregar(primerNodo);
	agregar(segundoNodo);
	agregar(tercerNodo);
	Nodo *i=primerNodo;
	while(i!=NULL){
		printf("%.2f\n",i->dato);
		i=i->sgte;
	}
	return 0;
}
