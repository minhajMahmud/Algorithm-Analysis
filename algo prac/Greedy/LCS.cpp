#include <bits/stdc++.h>
using namespace std;

char x[10], y[10], b[10][10]; // Arrays for input strings and backtracking
int c[10][10];               // Array to store LCS length

void print(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 'c') {
        print(i - 1, j - 1); // Move diagonally up-left
        cout << x[i - 1];   // Print the character in LCS
    } else if (b[i][j] == 'u') {
        print(i - 1, j);    // Move up
    } else {
        print(i, j - 1);    // Move left
    }
}
void lcs(int m, int n) {
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0; // Initialize first column
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0; // Initialize first row
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) { 
                c[i][j] = c[i - 1][j - 1] + 1; // Match case
                b[i][j] = 'c';               // Mark as diagonal move
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];       // Take value from above
                b[i][j] = 'u';              // Mark as upward move
            } else {
                c[i][j] = c[i][j - 1];       // Take value from left
                b[i][j] = 'l';              // Mark as leftward move
            }
        }
    }
}

int main() {
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;

    int m = strlen(x);
    int n = strlen(y);

    lcs(m, n);  // Compute LCS
    cout << "LCS is: ";
    print(m, n); // Print LCS
    cout << endl;

    return 0;
}
