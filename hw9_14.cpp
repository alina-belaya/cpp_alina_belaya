#include <iostream>
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

void multiply(int** mas3, int n, int k, int** mas1, int** mas2, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			mas3[i][j] = 0;
			for (int l = 0; l < m; l++) {
				mas3[i][j] += mas1[i][l] * mas2[l][j];
			}
		}
}

int main() {
	size_t n, m, k;
	cout << "Enter n = ";
	cin >> n;
	cout << "Enter m = ";
	cin >> m;
	cout << "Enter k = ";
	cin >> k;

	int** mat1 = ReserveArray(n, m);
	cout << "The first matrix:" << endl;
	EnterArray(mat1, n, m);

	int** mat2 = ReserveArray(m, k);
	cout << "\nThe second matrix:" << endl;
	EnterArray(mat2, m, k);

	cout << "\nThe first matrix is:" << endl;
	PrintArray(mat1, n, m);

	cout << "\nThe second matrix is:" << endl;
	PrintArray(mat2, m, k);

	int** mat3 = ReserveArray(n, k);
	multiply(mat3, n, k, mat1, mat2, m);

	cout << "\nResult of multiplication is:" << endl;
	PrintArray(mat3, n, k);
}