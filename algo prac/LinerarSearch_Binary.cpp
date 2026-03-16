#include <iostream>
#include <algorithm> // For sort
#include <chrono>    // For measuring execution time
using namespace std;
using namespace chrono;

// Linear Search Function
bool linearSearch(int n, int a[], int search) {
    for (int i = 0; i < n; i++) {
        if (a[i] == search) {
            return true; // Found
        }
    }
    return false; // Not Found
}

// Binary Search Function
bool binarySearch(int n, int a[], int search) {
    sort(a, a + n); // Binary search requires sorted data
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + right / 2; // Avoid overflow
        if (a[mid] == search) {
            return true; // Found
        } else if (a[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false; // Not Found
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "The elements are: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int search;
    cout << "Enter the element to search for: ";
    cin >> search;

    while (true) {
        cout << "\nMenu:\n1. Linear Search\n2. Binary Search\n3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Performing Linear Search...\n";
                auto start = high_resolution_clock::now();
                bool found = linearSearch(n, a, search);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                if (found) {
                    cout << "Element found. Time taken: " << duration.count() << " microseconds\n";
                } else {
                    cout << "Element not found. Time taken: " << duration.count() << " microseconds\n";
                }
                break;
            }

            case 2: {
                cout << "Performing Binary Search...\n";
                auto start = high_resolution_clock::now();
                bool found = binarySearch(n, a, search);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                if (found) {
                    cout << "Element found. Time taken: " << duration.count() << " microseconds\n";
                } else {
                    cout << "Element not found. Time taken: " << duration.count() << " seconds\n";
                }
                break;
            }

            case 3:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
