#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Function to add two matrices
void addMatrix(int n, int A[][100], int B[][100], int C[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][100], int B[][100], int C[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply matrices using divide and conquer
void multiplyMatrix(int n, int A[][100], int B[][100], int C[][100]) {
    // Base case: Single element matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into submatrices
    int mid = n / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int C11[100][100] = {0}, C12[100][100] = {0}, C21[100][100] = {0}, C22[100][100] = {0};
    int P1[100][100], P2[100][100], P3[100][100], P4[100][100];
    int P5[100][100], P6[100][100], P7[100][100], temp[100][100];

    // Fill submatrices
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Recursive calls
    multiplyMatrix(mid, A11, B11, P1);
    multiplyMatrix(mid, A12, B21, temp);
    addMatrix(mid, P1, temp, C11);

    multiplyMatrix(mid, A11, B12, P2);
    multiplyMatrix(mid, A12, B22, temp);
    addMatrix(mid, P2, temp, C12);

    multiplyMatrix(mid, A21, B11, P3);
    multiplyMatrix(mid, A22, B21, temp);
    addMatrix(mid, P3, temp, C21);

    multiplyMatrix(mid, A21, B12, P4);
    multiplyMatrix(mid, A22, B22, temp);
    addMatrix(mid, P4, temp, C22);

    // Combine submatrices into final result
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (must be a power of 2): ";
    cin >> n;

    int A[100][100], B[100][100], C[100][100] = {0};

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    auto start = high_resolution_clock::now();
    multiplyMatrix(n, A, B, C);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Time taken for matrix multiplication: " << duration.count() << " microseconds" << endl;

    return 0;
}
