#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Max Heap
    void insert(int val)
    {
        // 1. insert at last index
        // 2. compare with parent (index/2)

        // increase the size to insert at last index
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        // 1. swap last index with root
        // 2. remove last node
        // 3. to correct position
        if (size == 0)
        {
            cout << "nothing to delete";
            return;
        }

        // 1.
        arr[1] = arr[size];

        // 2.
        size--;

        // to correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

// Heapify Algo
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}


// Heap Sort
// 1. First index with last index swap
// 2. Decrease size
// 3. Root node to correct position
void heapSort(int arr[], int n) {
    
    int size = n;  // heap size starts from n
    while (size > 1) {
        // Swap the root (arr[0]) with the last element in the heap
        swap(arr[0], arr[size - 1]);
        
        // Reduce the heap size by 1 (excluding the last element)
        size--;
        
        // Call heapify to restore the max-heap property
        heapify(arr, size, 0); // Heapify the root (index 0) of the reduced heap
    }
}

int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = {
        -1, 54, 53, 55, 52, 50};

    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "printing the heap:" << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "printing the heap:" << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    // max Heap

    priority_queue<int> maxheap;
    maxheap.push(2);
    maxheap.push(1);
    maxheap.push(5);
    cout << "top: " << maxheap.top();
    maxheap.pop();
    cout << "top: " << maxheap.top();



    // Min Heap using pq
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(2);
    minheap.push(1);
    minheap.push(5);
    cout << "top: " << minheap.top();
    minheap.pop();
    cout << "top: " << minheap.top();

    return 0;
}
