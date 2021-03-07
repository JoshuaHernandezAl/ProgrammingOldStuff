#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dato;
    struct Nodo *sgte;
}Nodo;

Nodo *primer=NULL;
Nodo *ultimo=NULL;

void agregar(Nodo *nodo){
    nodo-> sgte=NULL;
    if(primer==NULL){
        primer= nodo;
        ultimo=nodo;
    }
    else{
        ultimo->sgte=nodo;
        ultimo=nodo;
    }
}
int main()
{
    Nodo *nodo1=malloc(sizeof(Nodo));
    nodo1->dato=1;
    Nodo *nodo2=malloc(sizeof(Nodo));
    nodo2->dato=2;
    agregar(nodo1);
    agregar(nodo2);
    Nodo *i=nodo1;
    while(i!=NULL){
        printf("%d\n",i->dato);
        i=i->sgte;
    }
    return 0;
}

