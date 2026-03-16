#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function to analyze the recurrence using Master Theorem
void masterTheorem(double a, double b, double m, double k) {
    double logValue = log(a) / log(b);  // Calculate log_b(a)

    // Prepare n^logValue as a string for output
    string nPowerLog = "n^" + to_string(logValue);

    // Check cases based on Master Theorem
    if (fabs(m - logValue) < 1e-9) { // Case: log_b(a) == m
        cout << "Master Theorem - Case 1" << endl;
        if (k != 0) {
            cout << "T(n) = O(" << nPowerLog << " * (logn)^" << k + 1 << ")" << endl;
        } else {
            cout << "T(n) = O(" << nPowerLog << " * logn)" << endl;
        }
    } else if (logValue > m) { // Case: log_b(a) > m
        cout << "Master Theorem - Case 2" << endl;
        cout << "T(n) = O(" << nPowerLog << ")" << endl;
    } else { // Case: log_b(a) < m
        cout << "Master Theorem - Case 3" << endl;
        string func = "n^" + to_string(m);
        if (k != 0) {
            func += " * (logn)^" + to_string(k); // Add logn terms if k > 0
        }
        cout << "T(n) = O(" << func << ")" << endl;
    }
}

int main() {
    double a, b, m, k;

    // Input values for a, b, m (exponent of n), and k (exponent of log n)
    cout << "Enter values for a, b, m (exponent of n), and k (exponent of logn): ";
    cin >> a >> b >> m >> k;

    // Handle invalid cases
    if (m == -1) {
        cout << "Case does not apply: Invalid" << endl;
        return 0;
    }

    // Call Master Theorem function
    masterTheorem(a, b, m, k);

    return 0;
}
