#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio; // value-to-weight ratio
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Sort by ratio in descending order
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items based on value-to-weight ratio in descending order
    sort(arr, arr + n, compare);

    int curWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Total value of the knapsack

    // Loop over all items to take them based on sorted order
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            // If the item can fit completely, take it fully
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // Otherwise, take the fraction of the item
            int remainingCapacity = W - curWeight;
            finalValue += arr[i].value * ((double) remainingCapacity / arr[i].weight);
            break; // No more capacity left in the knapsack
        }
    }

    return finalValue; // Return the maximum value achievable
}

int main() {
    int n = 3, W = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};

    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (double) arr[i].value / arr[i].weight;
    }

    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value in the knapsack: " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}
