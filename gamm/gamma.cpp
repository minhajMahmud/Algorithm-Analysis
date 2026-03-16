#include <iostream>
#include <string>
/*Name mahmudul hasan
MUH2225029M
mahmudul2517@student.nstu.edu.bd
*/
using namespace std;
void occ(const string& dna) {
    int countA = 0, countC = 0, countG = 0, countT = 0;
    char curr = NULL; 
    int Count = 0;  
    for (int i = 0; i < dna.length(); ++i) {
        if (dna[i] == curr) {
            ++Count;
        } else {
            if (curr != NULL) {
                cout << curr << " occur"<< Count << " times." << endl;
            }
            curr = dna[i]; 
            Count = 1; 
        }
    }
    if (curr != NULL) {
        cout << curr << " occur"<< Count << "times." << endl;
    }
}
int main() {
    string dna;
    while (getline(cin, dna)) {
        occ(dna);
    }
    return 0;
}
