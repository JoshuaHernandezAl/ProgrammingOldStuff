#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Persona.h"
using namespace std;

int main()
{
    //ofstream  aSal("nombre.txt"), aSal2("nombre2.txt");
    int m,n,i,j,k,nC;
    Persona *VP, *VP2, *VP3;
    /*cout<<"Cuantas personas se van a ingresar?"<<endl;
    cin>>n;
    VP=new Persona[n];
    for(i=0;i<n;i++){
        cin>>VP[i];
    }
    aSal<<n<<endl;
    for(i=0;i<n;i++){
        aSal<<VP[i];
    }
    aSal.close();
    delete [] VP;

    cout<<"Cuantas personas se van a ingresar?"<<endl;
    cin>>m;
    VP2=new Persona[m];
    for(j=0;j<m;j++){
        cin>>VP2[j];
    }
    aSal<<m<<endl;
    for(j=0;j<m;j++){
        aSal2<<VP2[j];
    }
    aSal2.close();
    delete [] VP2;*/
    string datos;
    ifstream aEnt("nombre.txt");
    getline(aEnt,datos);
    n=atoi(datos.c_str());
    VP= new Persona [n];
    for(i=0;i<n;i++){
        aEnt>>VP[i];
    }
    for(i=0;i<n;i++){
        cout<<VP[i];
    }
    ifstream aEnt2("nombre2.txt");
    getline(aEnt2,datos);
    m=atoi(datos.c_str());
    VP2= new Persona [m];
    for(j=0;j<m;j++){
        aEnt2>>VP2[j];
    }
    for(j=0;j<m;j++){
        cout<<VP2[j];
    }
    system("pause");
    system("cls");
   nC=m+n;
    VP3=new Persona[nC];
    for(i=0,j=0,k=0;k<nC;k++){
        if(i<n && j<m && VP[i].dameTuAPaterno()<=VP2[j].dameTuAPaterno())
            VP3[k]=VP[i++];
        else if(i<n && j<m && VP[i].dameTuAPaterno()>VP2[j].dameTuAPaterno())
            VP3[k]=VP2[j++];
        else if(i==n)
            VP3[k]=VP2[j++];
        else
            VP3[k]=VP[i++];
    }
    for(k=0;k<nC;k++){
        cout<<VP3[k];
    }
    ofstream vResultante("VectorResul.txt");
    for(k=0;k<nC;k++){
        vResultante<<VP3[k];
    }
    vResultante.close();
    delete [] VP;
    delete [] VP2;
    delete [] VP3;x|
    return 0;
}
