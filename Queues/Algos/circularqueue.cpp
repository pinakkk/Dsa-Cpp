#include <iostream>
using namespace std;

class CircularQueue {
    int *arr, size, front, rear, capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool enqueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = 0;
            rear = -1;
            size = 0;
        } else {
            front = (front + 1) % capacity;
            size--;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);

    while (!q.isEmpty()) {
        cout << q.getFront() << endl;
        q.dequeue();
    }

    cout << "Queue operations performed successfully!" << endl;
    return 0;
}
