#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Polinomio.h"

void formulaGeneral(void);

void newtonRaphson(Complejo xi, float eS,Polinomio& p);
using namespace std;

int main(void){
  float cifras;
    float eS=0;
    Complejo x0,x;
    Polinomio p,a;

    formulaGeneral();
    printf("\nMétodo de Newton - NewtonRaphson. Ingresa un valor cercano donde podría encontrarse la raíz:\n\n");
    p.ingresaPolinomio();
    cout<<endl<<"Ingresa x0: ";
    cin>>x0;
    cout<<"Cuantas cifras significativas de precision?: ";
    cin>>cifras;
    eS = 0.5*pow(10,(2-cifras));


    newtonRaphson(x0,eS,p);

    cout<<"\n\nComprueba que el metodo de Newton-Raphson encontro la raiz: \n\n";
    cout<<"\nIngresa x: ";
    cin>>x;
  // printf("f(%f) = %f\n\n\n",x,p.eval;

    return 0;

    return 0;
}

void formulaGeneral(void){
    int a=3,b=6,c=-4;
    float x1,x2;

  x1 = (-b + sqrt(pow(b,2)- (4*a*c))) / (2*a);
  x2 = (-b - sqrt(pow(b,2)- (4*a*c))) / (2*a);
  printf("f(x) = 3x^2 + 6x -4\n\n");
  printf("Calculadas analíticamente, con la fórmula general, las ríces están en:\n\n");
  printf("x1 = %f\nx2 = %f\n\n\n",x1,x2);
}


void newtonRaphson(Complejo xi, float eS,Polinomio& p){

    float epsilon;
    Complejo  xs;
      Polinomio d;
    d.deriva(p);


    printf("\n\nxi\t\t| x i+1\t\t| epsilon\n\n");
    while(true){
        xs = xi - (p.evalua(xi)/d.evalua(xi));

            epsilon = fabs((xs-xi)/(xs))*100;
            printf("%f\t| %f\t| %f\n",xi,xs,epsilon);

            if(epsilon<eS){
                cout<<"hay raiz en: "<<xs<<endl;
                break;
            }
            printf("%f\t| %f\t|\n",xi,xs);
            xi = xs;

        }


        }

