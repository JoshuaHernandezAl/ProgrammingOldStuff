#include <iostream>
#include <stdlib.h>
using namespace std;
void leeMatriz(float** X, int m, int n);
void muestraMatriz(float** X, int m, int n);

int main(void){
	float **M;
	int m, n, i;
	cout << "Dame m ";
	cin >> m;
	cout << "Dame n ";
	cin >> n;
	system("cls");

	if (m <= 0 || n <= 0)
		cout << "Orden invalido..." << endl;
	else {
		M = new float*[m];
		for (i = 0; i < m; i++)
			M[i] = new float[n];

		leeMatriz(M, m, n);
		system("cls");
		muestraMatriz(M, m, n);

		for (i = 0; i < m; i++)
			delete M[i];
		delete[] M;
	}

	system("pause");
    return 0;
}

void leeMatriz(float** X, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << "Ingresa [" << i << "][" << j << "] ";
			cin >> X[i][j];
		}
	}
}
void muestraMatriz(float** X, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << X[i][j] << "\t";
		}
		cout << endl;
	}
}

