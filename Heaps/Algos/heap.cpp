// You are using GCC
#include <iostream> 
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val){
        size++;
        
        int index = size;
        arr[index] = val;
        
        while(index>1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    
    void print(){
        for(int i = 1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void deletefromheap(){
        if(size==0){
            cout << "no delete" << endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;
        
        int i=1; 
        
        while(i<size){
            int left = 2 * i;
            int right = (2*i) + 1;
            
            if(left < size && arr[i] < arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{
                return;
            }
        }
    }
};


void heapifyzerobased(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = (2*i) + 1;
    
    if(left <= size && largest < arr[left]){
        largest = left;
    }
    if(right <= size && largest < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapifyonebased(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = (2*i) + 1;
    
    if(left < size && largest < arr[left]){
        largest = left;
    }
    if(right < size && largest < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[i], int i){
    int size = ;
    
    while(size > 1){
        // step1
        swap(arr[size], arr[i]);
        size--;
        
        // step 2
        heapifyzerobased(arr, size, i);
    }
}

int main(){
    
    heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.deletefromheap();
    // h.print();
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    
    for(int i=n/2; i>1; i--){
        heapify(arr, n, i);
    }
    
    cout << "printing" << endl;
    
    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapsort(arr,n);
    
    return 0;
}
