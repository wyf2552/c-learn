#include <iostream>

using namespace std;

const int SIZE = 3;

void inputMatrix(int matrix[SIZE][SIZE], const char* name) {
    cout << "输入" << name << "的9个元素 (3x3矩阵):" << endl;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> matrix[i][j];
}

void addMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void printMatrix(int matrix[SIZE][SIZE], const char* name) {
    cout << name << " =" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    inputMatrix(A, "A");
    inputMatrix(B, "B");

    addMatrices(A, B, C);

    printMatrix(C, "C = A + B");

    return 0;
}