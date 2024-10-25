#include <iostream>
using namespace std;

int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int cnt = 0; // Initialize count to 0

    for (int i = start + 1; i <= end; i++) { // Include end in the loop
        if (arr[i] < pivot) {
            cnt++;
        }
    }

    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    int i = start; // i will track elements less than pivot
    int j = end;   // j will track elements greater than pivot

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quicksort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int p = partition(arr, start, end);

    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}

int main() {
    int size;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free allocated memory
    return 0;
}
