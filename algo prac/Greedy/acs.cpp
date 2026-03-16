#include <iostream>
#include <algorithm>  // For the sort function

using namespace std;

struct Activity {
    int start, finish;
};

// Comparator function to sort by finish time (ascending order)
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;  // Sort by finish time in ascending order
}

// Function to perform activity selection
void activitySelection(Activity arr[], int n) {
    // Sort activities by their finish time
    sort(arr, arr + n, compare);

    // Select the first activity
    cout << "Selected activities:" << endl;
    cout << "Start: " << arr[0].start << ", Finish: " << arr[0].finish << endl;

    // Process the remaining activities
    int i = 0;  // Last selected activity index
    for (int j = 1; j < n; j++) {
        // If the current activity's start time is greater than or equal to the finish time of the last selected activity
        if (arr[j].start >= arr[i].finish) {
            // Select this activity
            cout << "Start: " << arr[j].start << ", Finish: " << arr[j].finish << endl;
            i = j;  // Update the index of the last selected activity
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity arr[n];  // Declare the array with size n

    // Input the activities' start and finish times
    cout << "Enter the activities' start and finish times (start finish):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> arr[i].start >> arr[i].finish;  // Input the start and finish times of each activity
    }

    // Call the activity selection function
    activitySelection(arr, n);

    return 0;
}
