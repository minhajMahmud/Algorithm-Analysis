#include <iostream>
#include <algorithm>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    // Create a 2D DP table to store the maximum value at each weight capacity
    int dp[n + 1][W + 1];

    // Initialize the table with 0s, as no value can be obtained with 0 items or 0 weight
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Fill the DP table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If the weight of the current item is less than or equal to the current weight capacity
            if (wt[i - 1] <= w) {
                // Either include the item or exclude it
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                // If the weight of the item is greater than the current weight capacity, don't include it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[n][W], which is the bottom-right cell of the DP table
    return dp[n][W];
}

int main() {
    int W = 50; // Maximum weight capacity of the knapsack
    int val[] = {60, 100, 120}; // Values (profits) of the items
    int wt[] = {10, 20, 30}; // Weights of the items
    int n = sizeof(val) / sizeof(val[0]); // Number of items

    // Call the knapsack function
    int result = knapsack(W, wt, val, n);

    // Output the result
    cout << "Maximum value in knapsack: " << result << endl;

    return 0;
}
