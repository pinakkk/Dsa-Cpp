#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    for(int i=0; i<size -1; i++){
        for(int j=0; j<size - i -1; j++){
            if(arr[j] > arr[j+1]){
                // swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int size; cin >> size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    printArray(arr, size);

    BubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}