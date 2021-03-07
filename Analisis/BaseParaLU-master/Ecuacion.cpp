#include "Ecuacion.h"


Ecuacion::Ecuacion(void){
    ini = NULL;
}
Ecuacion::~Ecuacion(void){
    eliminaEcuacion();
}
bool Ecuacion::estaVacio(void){
    return ini == NULL;
}
void Ecuacion::muestraEcuacion(void){
    NodoP* aux=ini;
    while(aux!=NULL){
        if(aux->dameSig()!=NULL && aux!=ini && aux->dameDato().dameCoeficiente() > 0)
            cout<<"+";
        else if(aux->dameSig()==NULL)
            cout<<"= ";
        cout<<aux->dameDato();

        aux = aux->dameSig();
        cout<<" ";
    }
}
void Ecuacion::eliminaEcuacion(void){
    NodoP* aux=ini;
    while(ini!=NULL){
        ini = ini->dameSig();
        delete aux;
        aux = ini;
    }
}
void Ecuacion::insertaTermino(Termino A){
    if(A.dameCoeficiente()!=0){ //Solo inserta terminos cuyo coeficiente sea diferente de cero.

        if(estaVacio() || A.dameNombre() < ini->dameDato().dameNombre())//Si esta vacio el polinomio o el exponente del termino a insertar es mayor al exponente del termino en ini
            ini = new NodoP(A, ini);
        else if(A.dameNombre() == ini->dameDato().dameNombre()){//Si el termino a insertar y el primer termino tienen el mismo exponente
            A.modificaCoeficiente(A.dameCoeficiente() + ini->dameDato().dameCoeficiente());
            ini->modificaDato(A);
        }
        else{
            NodoP* a1 = ini;
            NodoP* a2 = ini->dameSig();
            while(a2 != NULL &&
                  A.dameNombre() > a2->dameDato().dameNombre()
                  ){
                a1 = a1->dameSig();
                a2 = a2->dameSig();
            }
            if(a2!=NULL &&
               A.dameNombre() == a2->dameDato().dameNombre()
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
void Ecuacion::insertaTermino(double c, string N){
    Termino A(c,N);
    insertaTermino(A);
}
bool Ecuacion::eliminaTermino(Termino A){
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
bool Ecuacion::eliminaTermino(double c, string N){
    Termino A(c,N);
    return eliminaTermino(A);
}
void Ecuacion::ingresaEcuacion(void){
    double c;
    string N;
    this->eliminaEcuacion();

    do{
        cout<<endl<<"Ingresa coeficiente del termino (0, para terminar)"<<endl;
        cin>>c;
        if(c==0)
            break;
        cout<<"variable del termino? ";
        cin>>N;
        this->insertaTermino(c,N);
    }while(true);
        cout<<endl<<"Ingresa termino independiente "<<endl;
        cin>>c;
        this->insertaTermino(c,"~");
}

