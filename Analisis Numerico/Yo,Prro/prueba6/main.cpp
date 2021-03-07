#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Dfhae
{
    private:
        int x;
        float h;
        double valor;

    public:
        Dfhae(void);
        ~Dfhae(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);

};
Dfhae::Dfhae(void){
    x = 0;
    h=0.0;
}
Dfhae::~Dfhae(void){
}

void Dfhae::pideleAlUsuarioTusDatos(void){
	system("cls");
    cout<<"Introduce el valor de x"<<endl;
    cin>>x;
    cout<<endl<<"Introduce el valor de h"<<endl;
    cin>>h;
    cout<<endl;
}

void Dfhae::muestraTusDatos(void){
    int op,opp;
    float F11,F12,F21,F22,F31,F32,F41,F42;
    F11=F12=F21=F22=F31=F32=F41=F42=0.0;
	do{
    cout<<"1) Primera derivada\n"<<endl;
    cout<<"2) Segunda derivada\n"<<endl;
    cout<<"3) Tercera derivada\n"<<endl;
    cout<<"4) Cuarta derivada\n"<<endl;
    cout<<"5) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;
    switch(op){
    case 1:
    	system("cls");
        do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    cout<<endl;
    switch(opp){
    case 1:
    	F11=(log(x+h)-log(x))/h;
    	cout<<"Resultado: "<<F11<<endl;
    	system("pause");
    	exit(1);
        break;
    case 2:
        F12=(-log(x+(2*h))+(4*log(x+h))-(3*log(x)))/(2*h);
        cout<<"Resultado: "<<F12<<endl;
        system("pause");
    	exit(1);
        break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);
        break;
    case 2:
        system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F21=(log(x+(2*h))-(2*log(x+h))+log(x))/pow(h,2);
    	cout<<"Resultado: "<<F21<<endl;
    	system("pause");
    	exit(1);
        break;
    case 2:
        F22=(-log(x+(3*h))+(4*log(x+(2*h)))-(5*log(x+h))+(2*log(x)))/pow(h,2);
        cout<<"Resultado: "<<F22<<endl;
        system("pause");
    	exit(1);
        break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);
        break;
    case 3:
    	system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F31=(log(x+(3*h))-(3*log(x+(2*h)))+(3*log(x+h))-log(x))/pow(h,3);
    	cout<<"Resultado: "<<F31<<endl;
    	system("pause");
    	exit(1);
        break;
    case 2:
        F32=(-(3*log(x+(4*h)))+(14*log(x+(3*h)))-(24*log(x+(2*h)))+(18*log(x+h))-(5*log(x)))/(2*pow(h,3));
        cout<<"Resultado: "<<F32<<endl;
        system("pause");
    	exit(1);
        break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);
	break;
    case 4:
    	system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F41=(log(x+(4*h))-(4*log(x+(3*h)))+(6*log(x+(2*h)))-(4*log(x+h))+log(x))/pow(h,4);
    	cout<<"Resultado: "<<F41<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F42=(-(2*log(x+(5*h)))+(11*log(x+(4*h)))-(24*log(x+(3*h)))+(26*log(x+(2*h)))-(14*log(x+h))+(3*log(x)))/pow(h,4);
        cout<<"Resultado: "<<F42<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);
  
    	break;
    case 5:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=5);

}
class Dfc
{
    private:
        int x;
        float h;
        double valor;

    public:
        Dfc(void);
        ~Dfc(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);

};
Dfc::Dfc(void){
    x = 0;
    h=0.0;
}
Dfc::~Dfc(void){
}

void Dfc::pideleAlUsuarioTusDatos(void){
    system("cls");
    cout<<"Introduce el valor de x"<<endl;
    cin>>x;
    cout<<endl<<"Introduce el valor de h"<<endl;
    cin>>h;
    cout<<endl;
}

void Dfc::muestraTusDatos(void){
    int op,opp;
    float F11,F12,F21,F22,F31,F32,F41,F42;
    F11=F12=F21=F22=F31=F32=F41=F42=0.0;
	do{
    cout<<"1) Primera derivada\n"<<endl;
    cout<<"2) Segunda derivada\n"<<endl;
    cout<<"3) Tercera derivada\n"<<endl;
    cout<<"4) Cuarta derivada\n"<<endl;
    cout<<"5) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;
    switch(op){
    case 1:
        system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F11=(log(x+h)-log(x-h))/(2*h);
    	cout<<"Resultado: "<<F11<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F12=(-log(x+(2*h))+(8*log(x+h))-(8*log(x-h))+log(x-(2*h)))/(12*h);
        cout<<"Resultado: "<<F12<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

        break;
    case 2:
        system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F21=(log(x-h)+log(x+h)-(2*log(x)))/pow(h,2);
    	cout<<"Resultado: "<<F21<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F22=(-log(x-(2*h))+(16*log(x-h))-log(x+(2*h))+(16*log(x+h))-(30*log(x)))/(12*pow(h,2));
        cout<<"Resultado: "<<F22<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

        break;
    case 3:
    	system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F31=(-log(x-(2*h))+log(x+(2*h))-(2*log(x+h))+(2*log(x-h)))/(8*pow(h,3));
    	cout<<"Resultado: "<<F31<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        cout<<"Resultado: No esta bien la formula"<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);
    	break;
    case 4:
    	system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F41=(-(4*log(x-h))+log(x-(2*h))+log(x+(2*h))-(4*log(x+h))+(6*log(x)))/pow(h,4);
    	cout<<"Resultado: "<<F41<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F42=((12*log(x-(2*h)))-log(x-(3*h))-(39*log(x-h))-log(x+(3*h))+(12*log(x+(2*h)))-(39*log(x+h))+(56*log(x)))/(6*pow(h,4));
        cout<<"Resultado: "<<F42<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

    	break;
    case 5:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=5);

}
class Dfhas
{
    private:
        int x;
        float h;
        double valor;

    public:
        Dfhas(void);
        ~Dfhas(void);
        void pideleAlUsuarioTusDatos(void);
        void muestraTusDatos(void);

};
Dfhas::Dfhas(void){
    x = 0;
    h=0.0;
}
Dfhas::~Dfhas(void){
}

void Dfhas::pideleAlUsuarioTusDatos(void){
    system("cls");
    cout<<"Introduce el valor de x"<<endl;
    cin>>x;
    cout<<endl<<"Introduce el valor de h"<<endl;
    cin>>h;
    cout<<endl;
}

void Dfhas::muestraTusDatos(void){
    int op,opp;
    float F11,F12,F21,F22,F31,F32,F41,F42;
    F11=F12=F21=F22=F31=F32=F41=F42=0;
	do{
    cout<<"1) Primera derivada\n"<<endl;
    cout<<"2) Segunda derivada\n"<<endl;
    cout<<"3) Tercera derivada\n"<<endl;
    cout<<"4) Cuarta derivada\n"<<endl;
    cout<<"5) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;
    switch(op){
    case 1:
        system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F11=(-log(x-h)+log(x))/h;
    	cout<<"Resultado: "<<F11<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F12=(log(x-(2*h))-(4*log(x-h))+(3*log(x)))/(2*h);
        cout<<"Resultado: "<<F12<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

        break;
    case 2:
        system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F21=(log(x-(2*h))-(2*log(x-h))+log(x))/pow(h,2);
    	cout<<"Resultado: "<<F21<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F22=(-log(x-(3*h))+(4*log(x-(2*h)))-(5*log(x-h))+(2*log(x)))/pow(h,2);
        cout<<"Resultado: "<<F22<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

        break;
    case 3:
    	system("cls");
		do{
    cout<<"Este programa calcula sistemas de ecuaciones: \n"<<endl;
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F31=(-log(x-(3*h))+(3*log(x-(2*h)))-(3*log(x-h))+log(x))/pow(h,3);
    	cout<<"Resultado: "<<F31<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
        F32=((3*log(x-(4*h)))-(14*log(x-(3*h)))+(24*log(x-(2*h)))-(18*log(x-h))+(5*log(x)))/(2*pow(h,3));
        cout<<"Resultado: "<<F32<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

    	break;
    case 4:
    	system("cls");
		do{
    cout<<"1) Primeras Diferencias\n"<<endl;
    cout<<"2) Segundas Diferencias\n"<<endl;
    cout<<"3) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>opp;
    switch(opp){
    case 1:
    	F41=(log(x-(4*h))-(4*log(x-(3*h)))+(6*log(x-(2*h)))-(4*log(x-h))+log(x))/pow(h,4);
    	cout<<"Resultado: "<<F41<<endl;
        system("pause");
    	exit(1);
		break;
    case 2:
    	/*Esta formula puede estar mal revisar mañana en lab*/
        F42=(-(2*log(x-(5*h)))+(11*log(x-(4*h)))-(24*log(x-(3*h)))+(26*log(x-(2*h)))-(14*log(x-h))+(3*log(x)))/pow(h,4);
        cout<<"Resultado: "<<F42<<endl;
        system("pause");
    	exit(1);
		break;
    case 3:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(opp!=3);

    	break;
    case 5:
        cout<<"Hasta pronto"<<endl;
        system("pause");
    	exit(1);
		break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=5);

}
int main()
{
   Dfhae A;
   Dfc B;
   Dfhas C;
    int op;
    do{
    cout<<"Este programa calcula las derivadas de la funcion ln(x) utilizando el metodo de Diferencias Finitas: \n"<<endl;
    cout<<"1) Hacia Adelante\n"<<endl;
    cout<<"2) Centrales\n"<<endl;
    cout<<"3) Hacia Atras\n"<<endl;
    cout<<"4) Salir\n"<<endl;
    cout<<"Cual es tu opcion?\n"<<endl;
    cin>>op;

    switch(op){
    case 1:
        A.pideleAlUsuarioTusDatos();
        A.muestraTusDatos();
        break;
    case 2:
        B.pideleAlUsuarioTusDatos();
        B.muestraTusDatos();
        break;
    case 3:
    	C.pideleAlUsuarioTusDatos();
        C.muestraTusDatos();
        break;
    case 4:
        cout<<"Hasta pronto"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;  }
    system("pause");
    system("cls");
    }while(op!=4);
    return 0;
}
