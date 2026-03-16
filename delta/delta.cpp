#include <iostream>
#include <algorithm>
using namespace std;
struct aac {
    int start, finish;
};
/*Name mahmudul hasan
MUH2225029M
mahmudul2517@student.nstu.edu.bd
*/
bool compare(aac a, aac b) {
    return a.finish < b.finish;
}
void acs(aac arr[], int n) {
    sort(arr, arr + n, compare);
    aac select[1000];
    int Count = 0;
    select[Count++] = arr[0];
    int last= 0;
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[last].finish) {
     select[Count++] = arr[j];
            last = j;
        }
    }
    for (int i = 0; i < Count; i++) {
        cout <<"("<< select[i].start <<","<< select[i].finish <<")";
        if (i != Count - 1) cout <<",";
    }
}
int main() {
    char inpt[5000];
    cin.getline(inpt, 5000);
    // string inpt;
    // cin>>inpt;
    aac arr[1000];
    int n = 0;
    int start, finish;
    for (int i = 0; inpt[i] != '\0'; i++) {
        if (inpt[i] == '(') {
            sscanf(inpt+1, "(%d, %d)", &start, &finish);
            arr[n++] = {start, finish};
            while (inpt[i] != ')' && inpt[i] != NULL){
            i++;    
            } 
        }
    }
    if (n == 0) {
        return 0;
    }
    acs(arr, n);
    return 0;
}
