#include <iostream>
using namespace std;

// Function to calculate the nth Catalan number using dynamic programming
long long catalan(int n) {
    long long dp[n + 1];
    dp[0] = dp[1] = 1; // Base cases

    // Fill dp[] using the recursive formula
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    
    cout << "Number of binary search trees possible for " << n << " keys: " << catalan(n) << endl;

    return 0;
}
/*The code you provided is a simple and effective solution to calculate the number of binary search trees (BSTs) possible for a given number of keys using **Catalan numbers**.

### Key Explanation:
1. **Catalan Number**: The Catalan number formula gives the number of different binary search trees that can be made from `n` distinct keys. It is given by the recursive relation:

   \[
   C_n = \sum_{i=0}^{n-1} C_i \times C_{n-i-1}
   \]

   Where `C_0 = 1` and `C_1 = 1`.

2. **Dynamic Programming Approach**: The code uses dynamic programming to compute the Catalan number for a given `n`. This avoids recalculating values for subproblems, thus improving efficiency.

### Code Walkthrough:
1. **Input**: The program takes the number of keys `n` from the user.
2. **Catalan Function**: 
   - The function `catalan(int n)` computes the Catalan number for `n` using dynamic programming.
   - It initializes a `dp` array of size `n + 1` to store the intermediate results.
   - `dp[i]` holds the Catalan number for `i` keys.
   - The loop iterates through `i = 2` to `n` and calculates `dp[i]` using the recursive relation. For each `i`, it iterates through possible values of `j` to compute the sum of the products `dp[j] * dp[i-j-1]`.
3. **Output**: The program outputs the number of binary search trees that can be formed with `n` keys using the calculated Catalan number.

### Sample Input/Output:

#### Input:
```
Enter the number of keys: 3
```

#### Output:
```
Number of binary search trees possible for 3 keys: 5
```

### Example Breakdown:
For `n = 3`, the program calculates the number of possible binary search trees as:

- `C_0 = 1`
- `C_1 = 1`
- `C_2 = 2` (calculated as `C_0 * C_1 + C_1 * C_0`)
- `C_3 = 5` (calculated as `C_0 * C_2 + C_1 * C_1 + C_2 * C_0`)

Thus, there are 5 possible BSTs for 3 keys.

### Code in the simplest form:
The code is already in a simple format, and it effectively calculates the Catalan number using dynamic programming.

If you need further clarification or a more detailed explanation of how Catalan numbers work, feel free to ask!*/