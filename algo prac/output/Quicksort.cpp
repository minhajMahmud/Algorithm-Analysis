#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// Partition function using leftmost element as pivot
int partition(int arr[], int l, int r) {
    int pivot = arr[l]; // Leftmost element as pivot
    int i = l + 1;      // Start point next to pivot
    for (int j = l + 1; j <= r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[l], arr[i - 1]); // Place pivot in its correct position
    return i - 1;
}

// Quick Sort function
void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Measure time for Quick Sort
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the time taken
    cout << "Time taken for Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
