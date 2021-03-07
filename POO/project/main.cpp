#include <cstdlib>
#include <iostream>
#include "punto.h"
using namespace std;

int main(int argc, char *argv[])
{

   Punto A(1,2),B(3,4),C;
   cout<<"A("<<A.dameTuX()<<","<<A.dameTuY()<<")"<<endl
       <<"B("<<B.dameTuX()<<","<<B.dameTuY()<<")"<<endl
       <<"C("<<C.dameTuX()<<","<<C.dameTuY()<<")"<<endl;

       C.modificaTuX(A.dameTuX()+B.dameTuX());
       C.modificaTuY(A.dameTuY()+B.dameTuY());

       cout<<"A("<<A.dameTuX()<<","<<A.dameTuY()<<")"<<endl
           <<"+"<<endl
           <<"B("<<B.dameTuX()<<","<<B.dameTuY()<<")"<<endl
           <<"="<<endl
           <<"C("<<C.dameTuX()<<","<<C.dameTuY()<<")"<<endl<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;

}
