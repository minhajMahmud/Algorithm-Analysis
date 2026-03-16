#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// Partition function using leftmost element as pivot
int partition(int arr[], int l,int mid ,int r) {
    int n1=mid-l+1;
    int n2=r-mid;
    //make temporary
   int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        //merge
        int i=0  j=0,k=1;
         while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Quick Sort function
void mergeSort(int arr[], int l, int r,int mid) {
    if (l < r) {
mid=(l+r)/2;
        int pi = partition(arr, l, r);
        mergeSort(arr, r+1, mid);
        mergeSort(arr, l, r,mid);
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
