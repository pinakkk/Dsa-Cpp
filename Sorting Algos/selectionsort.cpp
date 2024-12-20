#include <iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int minIndex = i;
        for(int j= i+1; j<size; j++){
            if(arr[j]  < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
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

    // Perform selection sort
    selectionSort(arr, n);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}