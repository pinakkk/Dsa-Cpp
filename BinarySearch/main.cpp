#include <iostream>
using namespace std;


int BinarySearch(int arr[], int size, int target){
    int start, end; start = 0; end = size -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(target == mid){
            return mid;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    int result = BinarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
