#include <iostream>

using namespace std;

int main()
{
    float a;
    float* aPtr;
    float** aPtrPtr;
    a=5.67;
    aPtr=&a;
    aPtrPtr=&aPtr;
    cout<<"a= "<<a<<endl<<endl
    <<"&a= "<<&a<<endl<<endl
    <<"aPtr= "<<aPtr<<endl<<endl
    <<"&aPtr= "<<&aPtr<<endl<<endl
    <<"*aPtr= "<<*aPtr<<endl<<endl
    <<"aPtrPtr= "<<aPtrPtr<<endl<<endl
    <<"&aPtrPtr= "<<&aPtrPtr<<endl<<endl
    <<"*aPtrPtr="<<*aPtrPtr<<endl<<endl
    <<"**aPtrPtr="<<**aPtrPtr<<endl<<endl;
    return 0;
}
