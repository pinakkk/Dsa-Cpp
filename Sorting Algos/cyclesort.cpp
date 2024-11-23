#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int>& arr) {
    int n = arr.size();

    for (int start = 0; start < n - 1; ++start) {
        int item = arr[start];
        int pos = start;

        // Find the position where the item should be placed
        for (int i = start + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }

        // If the item is already in the correct position
        if (pos == start) continue;

        // Skip duplicates
        while (item == arr[pos]) {
            ++pos;
        }

        // Place the item in its correct position
        if (pos != start) {
            swap(item, arr[pos]);
        }

        // Rotate the rest of the cycle
        while (pos != start) {
            pos = start;
            for (int i = start + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }

            // Skip duplicates
            while (item == arr[pos]) {
                ++pos;
            }

            if (item != arr[pos]) {
                swap(item, arr[pos]);
            }
        }
    }
}

int main() {
    vector<int> arr = {4, 5, 1, 3, 2};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cycleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
