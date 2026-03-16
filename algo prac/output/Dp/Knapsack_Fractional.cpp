#include <bits/stdc++.h>
using namespace std;

// Recursive 0/1 Knapsack Function
int knapsack(int wt[], int val[], int w, int len) {
    if (len == 0 || w == 0) {
        return 0; // Base case: No items or weight capacity left
    }

    // If the current item's weight exceeds the remaining capacity, skip it
    if (wt[len - 1] > w) {
        return knapsack(wt, val, w, len - 1);
    } else {
        // Print to debug which choice is being made
        cout << "Considering item " << len << " with weight " << wt[len-1] << " and value " << val[len-1] << endl;
        int include = val[len - 1] + knapsack(wt, val, w - wt[len - 1], len - 1); // Include
        int exclude = knapsack(wt, val, w, len - 1);                              // Exclude
        cout << "Include: " << include << ", Exclude: " << exclude << endl;
        return max(include, exclude);
    }
}

int main() {
    int wt[] = {1  ,   3   ,  5   ,  4  ,   1     ,3     ,2 };
    int val[] = {10,15,7,8,9,4}; // Profit
    int w = 15; // Maximum weight capacity
    int len = sizeof(val) / sizeof(val[0]); // Number of items

    // Call the knapsack function
    int op = knapsack(wt, val, w, len);

    // Output the result
    cout << "Maximum value in knapsack: " << op << endl;

    return 0;
}
