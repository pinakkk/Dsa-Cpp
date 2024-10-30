#include <iostream>
using namespace std;

void merge(int *arr, int start, int end, int mid){
    int len1 = mid - start +1; int len2 = end - mid;
    int *first = new int[len1]; int *second = new int[len2]; int MainArrayIndex = start;
    for(int i=0; i<len1; i++){ first[i] = arr[MainArrayIndex++]; }
    for(int i=0; i<len2; i++){ second[i] = arr[MainArrayIndex++]; }

    int index1 = 0; int index2 = 0; MainArrayIndex = start;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){ arr[MainArrayIndex++] = first[index1++]; }
        else{ arr[MainArrayIndex++] = second[index2++]; }
    }
    while(index1 < len1){ arr[MainArrayIndex++] = first[index1++]; }
    while(index2 < len2){ arr[MainArrayIndex++] = second[index2++]; }
}

void mergesort(int *arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start)/2;

    mergesort(arr, start, mid); mergesort(arr, mid+1, end);

    merge(arr, start, end, mid);
}

int main(){
    int size; cin >> size;
    int *arr = new int[size];
    for(int i=0; i<size; i++){ cin >> arr[i]; }

    mergesort(arr, 0, size-1);

    for(int i=0; i<size; i++) { cout << arr[i] << " "; }
    return 0;
}