#include <stdlib.h>
#include <iostream>
using namespace std;

int fac(int);
int main(){
	int n,m;
	cout<<"NUmero: ";
	cin>>n;
	m=fac(n);
	cout<<m;
	return 0;
}
int fac(int n){
	if(n==0){
		n=1;
	}
	else{
		n=n*fac(n-1);
	}
	return n;
}
