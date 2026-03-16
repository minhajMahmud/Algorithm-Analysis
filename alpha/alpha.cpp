#include <iostream>
#include <cstring>
/*Name mahmudul hasan
MUH2225029M
mahmudul2517@student.nstu.edu.bd
*/
using namespace std;
void swap(char temp1[], char temp2[]) {
    for (int i = 0; i < 20; i++) {
        char temp = temp1[i];
        temp1[i] = temp2[i];
        temp2[i] = temp;
    }
}
void Sort(char arr[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
     if (strcmp(arr[j], arr[j + 1]) > 0) {
      swap(arr[j], arr[j + 1]); }
        }
    }
}
int main() {
    char alpha[][20] = {"try","float","byte","default","extends","package","throw","finally","switch", "super", "do", "assert", "new", "short", "catch", "break","synchronized","goto","return","case" };
    int size = sizeof(alpha) / sizeof(alpha[0]);
    Sort(alpha, size);
    for (int i = 0; i < size; i++) {
        cout << alpha[i] <<endl;
    }
    return 0;
}
