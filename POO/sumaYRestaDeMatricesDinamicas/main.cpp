#include <iostream>
#include <stdlib.h>
using namespace std;
template<typename T>
void leeMatriz(T** X, int m, int n);
template<typename T>
void muestraMatriz(T** X, int m, int n);
template<typename T>
T** generaMatriz(int m, int n, T tipo);
template<typename T>
void liberaMatriz(T** X, int m);
template<typename T>
void inicializaMatriz(T** X, int m, int n);
template<typename T>
void sumaDeMatrices(T** X, T** Y, T** Z, int m, int n);
template<typename T>
void restaDeMatrices(T** X, T** Y, T** Z, int m, int n);

int main(void){
	float **A, **B, **C, **D, tipo;
	int m1, n1, m2, n2, m3, n3, m4, n4, i;
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
	else if (m1 != m2 || n1 != n2)
			cout << "No pueden sumarse ni restarse..." << endl;
	else {
		m3 = m1;
		n3 = n1;
		m4 = m2;
		n4 = n2;
		A = generaMatriz(m1, n1,tipo);
		B = generaMatriz(m2, n2,tipo);
		C = generaMatriz(m3, n3,tipo);
		D = generaMatriz(m4, n4,tipo);
		system("cls");
		cout << "A" << endl;
		leeMatriz(A, m1, n1);
		system("cls");
		cout << "B" << endl;
		leeMatriz(B, m2, n2);

		system("cls");

		sumaDeMatrices(A, B, C, m3, n3);
		restaDeMatrices(A, B, D, m4, n4);

		cout << "A" << endl;
		muestraMatriz(A, m1, n1);
		cout << endl << "B" << endl;
		muestraMatriz(B, m2, n2);
		cout << endl << "C" << endl;
		muestraMatriz(C, m3, n3);
		cout << endl << "D" << endl;
		muestraMatriz(D, m3, n4);

		liberaMatriz(A, m1);
		liberaMatriz(B, m2);
		liberaMatriz(C, m3);
		liberaMatriz(D, m4);
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
T** generaMatriz(int m, int n, T tipo) {
	T** X;
	int i;

	X = new T*[m];
	for (i = 0; i < m; i++)
		X[i] = new T[n];

	inicializaMatriz(X, m, n);

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
void sumaDeMatrices(T** X, T** Y, T** Z, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			Z[i][j] = X[i][j] + Y[i][j];
}
template<typename T>
void restaDeMatrices(T** X, T** Y, T** Z, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			Z[i][j] = X[i][j] - Y[i][j];
}
