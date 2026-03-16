#include <iostream>
#include <climits>  // For LONG_MAX
using namespace std;

// Function to calculate the minimum cost of the optimal Binary Search Tree (BST)
long long optimalBSTCost(int n, double P[], double Q[]) {
    long long dp[n + 1][n + 1];  // dp[i][j] will store the minimum cost for keys[i] to keys[j]

    // Initialize dp[i][i] for base cases (empty subtrees, cost = Q[i])
    for (int i = 0; i <= n; i++) {
        dp[i][i] = Q[i];
    }

    // Build the dp table for increasing subproblem sizes
    for (int size = 2; size <= n; size++) {  // size is the length of the range we're solving for
        for (int i = 0; i <= n - size; i++) {  // i is the starting index
            int j = i + size - 1;  // j is the ending index
            dp[i][j] = LONG_MAX;  // Initialize the dp value as maximum
            long long sum = 0;

            // Calculate the sum of probabilities for keys[i] to keys[j]
            for (int k = i; k <= j; k++) {
                sum += P[k];  // Add probability of successful search
            }

            // Try placing the root at each possible position between i and j
            for (int r = i; r <= j; r++) {
                // Calculate the cost if r is the root
                long long cost = dp[i][r - 1] + dp[r + 1][j] + sum;
                dp[i][j] = min(dp[i][j], cost);  // Store the minimum cost
            }
        }
    }

    return dp[0][n];  // Return the cost for the entire tree
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;  // Input the number of keys
    
    double P[n + 1], Q[n + 1];  // Arrays to store successful and unsuccessful search probabilities
    
    cout << "Enter the probabilities P for successful search (size " << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> P[i];  // Input the successful search probabilities
    }
    
    cout << "Enter the probabilities Q for unsuccessful search (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++) {
        cin >> Q[i];  // Input the unsuccessful search probabilities
    }

    // Output the minimum cost for the optimal BST
    cout << "The minimum cost of the optimal BST is: " << optimalBSTCost(n, P, Q) << endl;

    return 0;
}
