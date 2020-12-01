#include <iostream>
#include <math.h>
using namespace std;

int** ReserveArray(int r, int c) {
	int** mat = new int* [r];
	for (int i = 0; i < r; i++) {
		mat[i] = new int[c];
	}
	return mat;
}


void EnterArray(int** mat, int row, int col) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> mat[i][j];
		}
}

void PrintArray(int** mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "\t" << mat[i][j];
		}
		cout << endl;
	}
}

void Change(int** mat, int n, int m) {
	for (int i = 0; i < m; i++) {
		if (mat[0][i] < 0 && mat[m][i] < 0) {
			int a = mat[0][i];
			mat[0][i] = mat[m][i];
			mat[m][i] = a;
		}
	}
	PrintArray(mat, n, m);
}

int main() {
	size_t n, m;
	cout << "Enter n = ";
	cin >> n;
	cout << "Enter m = ";
	cin >> m;

	int** mat = ReserveArray(n, m);
	cout << "The first matrix:" << endl;
	EnterArray(mat, n, m);

	cout << "\nMatrix is:" << endl;
	PrintArray(mat, n, m);

	cout << "\nResult is:" << endl;
	Change(mat, n, m);
}