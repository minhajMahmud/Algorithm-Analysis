#include <iostream>
using namespace std;

// Recursive function to check for subset sum
bool subsetSumRecursive(int arr[], int n, int target) {
    // Base cases
    if (target == 0) {
        return true; // A subset with sum 0 exists (empty subset)
    }
    if (n == 0) {
        return false; // No elements left, and target is not achieved
    }

    // Exclude the last element and check
    if (arr[n - 1] > target) {
        return subsetSumRecursive(arr, n - 1, target);
    }

    // Include or exclude the last element
    return subsetSumRecursive(arr, n - 1, target - arr[n - 1]) || 
           subsetSumRecursive(arr, n - 1, target);
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    // Call the recursive function
    if (subsetSumRecursive(arr, n, target)) {
        cout << "There is a subset with the given sum!" << endl;
    } else {
        cout << "No subset with the given sum." << endl;
    }

    return 0;
}
