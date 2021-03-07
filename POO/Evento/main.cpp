#include <iostream>
#include "Fecha.h"
#include "Hora.h"
#include "Evento.h"
using namespace std;

int main()
{
    Fecha F1(11,10,1999),F2;
    Hora H1(9,30,0),H2;
    Evento EN(F1,H1),evento;
    cout<<evento.dameTuA();
    /*cout<<EN.dameTuA()<<endl;
    cout<<EN.dameTuMes()<<endl;
    cout<<EN.dameTuD()<<endl;
    cout<<EN.dameTuHora()<<endl;
    cout<<EN.dameTuM()<<endl;
    cout<<EN.dameTuS()<<endl;*/

    return 0;
}
