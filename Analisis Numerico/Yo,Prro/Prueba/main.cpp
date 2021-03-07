#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

using namespace std;

class errores{
  private:
      int k,x,i;
      double va, ea, fac;
  public:
    void serie(void);
    double factorial(int);
};
void errores::serie(void){
    cout<<"dame el valor de X para el seno:"<<endl;
    cin>>x;
    k=0;
    va=0;
    do{
       va=va+pow(-1,k)*pow(x,2*k+1)/factorial(2*k+1);
        ea=fabs(sin(x)-va);
        k++;
        fac=1;
        }while(ea>=0.00000001);
        cout<<endl<<"el valor del seno es: "<<va<<endl;
}
double errores::factorial(int k){
	fac=1;
    if(k==0)
        return 1;
    else{
        for(i=1;i<=k; i++)
        fac=fac*i;
        return (fac);
        }
}

int main()
{
    errores obj;
    obj.serie();
    system("PAUSE");
    return 0;
}
