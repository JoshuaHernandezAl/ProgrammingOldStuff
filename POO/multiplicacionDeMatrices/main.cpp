#include <iostream>
#include <stdlib.h>
#include "Complejo.h"
using namespace std;
template<typename T>
void leeMatriz(T** X, int m, int n);
template<typename T>
void muestraMatriz(T** X, int m, int n);
template<typename T>
T** generaMatriz(int m, int n, T algo);
template<typename T>
void liberaMatriz(T** X, int m);
template<typename T>
void inicializaMatriz(T** X, int m, int n);
template<typename T>
void multiplicacionDeMatrices(T** X, T** Y, T** Z, int m, int n, int ele);

int main(void){
	Complejo **A, **B, **E, algo;
	int m1, n1, m2, n2, m5, n5, i;
	cout << "Dame m1 y n1 ";
	cin >> m1 >> n1;
	cout << "Dame m2 y n2 ";
	cin >> m2 >> n2;

	system("cls");

	if (m1 <= 0 || n1 <= 0 || m2 <= 0 || n2 <= 0) {
		if(m1 <= 0 || n1 <= 0)
			cout << "Orden de A invalido..." << endl;
		if (m2 <= 0 || n2 <= 0)
			cout << "Orden de B invalido..." << endl;
	}
	else if (n1 != m2)
			cout << "No pueden multiplicarse..." << endl;
	else {
		m5 = m1;
		n5 = n2;
		A = generaMatriz(m1, n1, algo);
		B = generaMatriz(m2, n2, algo);
		E = generaMatriz(m5, n5, algo);
		system("cls");
		cout << "A" << endl;
		leeMatriz(A, m1, n1);
		system("cls");
		cout << "B" << endl;
		leeMatriz(B, m2, n2);

		system("cls");

		multiplicacionDeMatrices(A, B, E, m5, n1, n5);

		cout << "A" << endl;
		muestraMatriz(A, m1, n1);
		cout << endl << "B" << endl;
		muestraMatriz(B, m2, n2);
		cout << endl << "E" << endl;
		muestraMatriz(E, m5, n5);

		liberaMatriz(A, m1);
		liberaMatriz(B, m2);
		liberaMatriz(E, m5);
	}

	system("pause");
    return 0;
}
template<typename T>
void leeMatriz(T** X, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << "Ingresa [" << i << "][" << j << "] ";
			cin >> X[i][j];
		}
	}
}
template<typename T>
void muestraMatriz(T** X, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << X[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T>
T** generaMatriz(int m, int n, T algo) {
	T** X;
	int i;

	X = new T*[m];
	for (i = 0; i < m; i++)
		X[i] = new T[n];

	//inicializaMatriz(X, m, n);

	return X;
}
template<typename T>
void liberaMatriz(T** X, int m) {
	int i;
	for (i = 0; i < m; i++)
		delete X[i];
	delete[] X;
}
template<typename T>
void inicializaMatriz(T** X, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			X[i][j] = 0;
}
template<typename T>
void multiplicacionDeMatrices(T** X, T** Y, T** Z, int m, int n, int ele) {
	int i, j, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < ele; j++)
			for (k = 0; k < n; k++)
				Z[i][j] =Z[i][j]+ X[i][k] * Y[k][j];
}

