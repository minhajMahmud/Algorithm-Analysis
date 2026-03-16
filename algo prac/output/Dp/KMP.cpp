#include <iostream>
#include <cstring>  // For strlen()
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPS(char pattern[], int m, int lps[]) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP search
void KMPSearch(char text[], char pattern[]) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern

    int lps[m];  // Array to hold the LPS values
    computeLPS(pattern, m, lps); // Preprocess the pattern

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index: " << (i - j) << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {

    string text, pattern;

    // Input text and pattern
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    // Call KMP Search
    KMPSearch(text, pattern);

    return 0;
}
