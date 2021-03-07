

#include "Polinomio.h"

Polinomio::Polinomio(void){
    ini = NULL;
}
Polinomio::~Polinomio(void){
    eliminaPolinomio();
}
bool Polinomio::estaVacio(void){
    return ini == NULL;
}
void Polinomio::muestraPolinomio(void){
    NodoP* aux=ini;
    while(aux!=NULL){
        if(aux!=ini && aux->dameDato().dameCoeficiente() > 0)
            cout<<"+";
        cout<<aux->dameDato();

        aux = aux->dameSig();
        cout<<" ";
    }
}
void Polinomio::eliminaPolinomio(void){
    NodoP* aux=ini;
    while(ini!=NULL){
        ini = ini->dameSig();
        delete aux;
        aux = ini;
    }
}
void Polinomio::insertaTermino(Termino A){
    if(A.dameCoeficiente()!=0){ //Solo inserta terminos cuyo coeficiente sea diferente de cero.

        if(estaVacio() || A.dameExponente() > ini->dameDato().dameExponente())//Si esta vacio el polinomio o el exponente del termino a insertar es mayor al exponente del termino en ini
            ini = new NodoP(A, ini);
        else if(A.dameExponente() == ini->dameDato().dameExponente()){//Si el termino a insertar y el primer termino tienen el mismo exponente
            A.modificaCoeficiente(A.dameCoeficiente() + ini->dameDato().dameCoeficiente());
            ini->modificaDato(A);
        }
        else{
            NodoP* a1 = ini;
            NodoP* a2 = ini->dameSig();
            while(a2 != NULL &&
                  A.dameExponente() < a2->dameDato().dameExponente()
                  ){
                a1 = a1->dameSig();
                a2 = a2->dameSig();
            }
            if(a2!=NULL &&
               A.dameExponente() == a2->dameDato().dameExponente()
               ){
                A.modificaCoeficiente(A.dameCoeficiente()+a2->dameDato().dameCoeficiente());
                a2->modificaDato(A);
                if(a2->dameDato().dameCoeficiente()==0)
                    eliminaTermino(A);
            }
            else
                a1->modificaSig(new NodoP(A,a2));
        }
    }
}
void Polinomio::insertaTermino(float c, int e){
    Termino A(c,e);
    insertaTermino(A);
}
bool Polinomio::eliminaTermino(Termino A){
    if(estaVacio()||
       (ini->dameSig()==NULL && A!=ini->dameDato())
       )
       return false;
    else if(A==ini->dameDato()){
        NodoP* a=ini->dameSig();
        delete ini;
        ini = a;
        return true;
    }
    else{
        NodoP* a1 = ini;
        NodoP* a2 = ini->dameSig();
        while(a2 != NULL &&
              a2->dameDato() != A
              ){
            a1 = a1->dameSig();
            a2 = a2->dameSig();
        }
        if(a2 == NULL)
            return false;
        else{
            a1->modificaSig(a2->dameSig());
            delete a2;
            return true;
        }
    }
}
bool Polinomio::eliminaTermino(float c, int e){
    Termino A(c,e);
    return eliminaTermino(A);
}
void Polinomio::ingresaPolinomio(void){
    float c;
    int e;
    this->eliminaPolinomio();

    do{
        cout<<"Ingresa coeficiente del termino (0, para terminar)"<<endl;
        cin>>c;
        if(c==0)
            break;
        cout<<"Ingresa exponente del termino "<<endl;
        cin>>e;
        this->insertaTermino(c,e);
    }while(true);
}
void Polinomio::suma(Polinomio& P1, Polinomio& P2){
    NodoP* aux;

    aux=P1.ini;
    while(aux!=NULL){
        insertaTermino(aux->dameDato());
        aux=aux->dameSig();
    }

    aux=P2.ini;
    while(aux!=NULL){
        insertaTermino(aux->dameDato());
        aux=aux->dameSig();
    }
}
void Polinomio::resta(Polinomio& P1, Polinomio& P2){
    NodoP* aux;

    aux=P1.ini;
    while(aux!=NULL){
        insertaTermino(aux->dameDato());
        aux=aux->dameSig();
    }

    aux=P2.ini;
    while(aux!=NULL){
        insertaTermino(aux->dameDato().dameCoeficiente()*-1
                       ,
                       aux->dameDato().dameExponente()
                       );
        aux=aux->dameSig();
    }
}
void Polinomio::multiplica(Polinomio& P1, Polinomio& P2){
    NodoP* aux1=P1.ini;
    NodoP* aux2;

    while(aux1!=NULL){
        aux2=P2.ini;
        while(aux2!=NULL){
            insertaTermino(
                aux1->dameDato().dameCoeficiente()
                *
                aux2->dameDato().dameCoeficiente()
                ,
                aux1->dameDato().dameExponente()
                +
                aux2->dameDato().dameExponente()
            );
            aux2=aux2->dameSig();
        }
        aux1=aux1->dameSig();
    }
}
void Polinomio::deriva(Polinomio& P){
    NodoP* aux;

    aux=P.ini;
    while(aux!=NULL){
        this->insertaTermino(
            aux->dameDato().dameCoeficiente() * aux->dameDato().dameExponente()
            ,
            aux->dameDato().dameExponente() - 1
        );
        aux=aux->dameSig();
    }
}
double Polinomio::evalua(double x){
    NodoP* aux=ini;
    double s = 0.0;
    while(aux!=NULL){
        s += aux->dameDato().dameCoeficiente() *
             pow(x, aux->dameDato().dameExponente());
        aux=aux->dameSig();
    }
    return s;
}
Complejo Polinomio::evalua(Complejo x){

    NodoP* aux=ini;
    Complejo r;

    while(aux!=NULL)
    {
         r = r + aux->dameDato().dameCoeficiente() *
             pow(x, aux->dameDato().dameExponente());

        aux=aux->dameSig();
    }
return r;


}

