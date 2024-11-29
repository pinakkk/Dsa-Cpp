#include <iostream>
using namespace std;

void merge(int *arr, int start, int end, int mid){
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy data to temp arrays
    for(int i = 0; i < len1; i++){
        first[i] = arr[start + i];
    }

    for(int i = 0; i < len2; i++){
        second[i] = arr[mid + 1 + i];
    }

    int index1 = 0, index2 = 0, mainArrayIndex = start;

    // Merge the two sorted subarrays
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy the remaining elements of first[]
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy the remaining elements of second[]
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    // Release dynamically allocated memory
    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start) / 2;

    // Left part
    mergesort(arr, start, mid);

    // Right part
    mergesort(arr, mid + 1, end);

    // Merge the sorted halves
    merge(arr, start, end, mid);
}

int main(){
    int size;
    cin >> size;
    int *arr = new int[size];
    
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    mergesort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
