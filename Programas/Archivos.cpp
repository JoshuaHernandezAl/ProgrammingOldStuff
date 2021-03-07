#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

void escribir();
void lectura();
void editar();
int main(){
	escribir();
	cout<<"Imprimiedo archivo"<<endl;
	lectura();
	editar();
	return 0;
}
void escribir(){
	ofstream archivo;
	string nombreA, texto;
	cout<<"Nombre del archivo: ";
	getline(cin,nombreA);
	archivo.open(nombreA.c_str(),ios::out);//abriendo archivo en modo escritura
	if(archivo.fail()){
		cout<<"Error en creacion del archivo :(";
		exit(1);
	}
	cout<<"Informacion: ";
	getline(cin,texto);
	archivo<<"Un semestre en una semana papa"<<endl;
	archivo<<texto;
	archivo.close();
}
void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("p.txt",ios::in);//abriendo archivo en modo lectura
	if(archivo.fail()){
		cout<<"No se logro abrir archivo :(";
		exit(1);
	}
	while(!archivo.eof()){//mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}
void editar(){
	ofstream archivo;
	string texto;
	archivo.open("p.txt",ios::app);//abriendo en modo añadir
	if(archivo.fail()){
		cout<<"No se logro abrir archivo :(";
		exit(1);
	}
	cout<<"Texto para agregar: ";
	getline(cin,texto);
	archivo<<texto<<endl;
	archivo.close();
}
