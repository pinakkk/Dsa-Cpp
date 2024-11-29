#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i -1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){

     int n;

    // Input array size and elements
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}