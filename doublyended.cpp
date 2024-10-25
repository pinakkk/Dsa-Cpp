#include <iostream>
using namespace std;

class Deque{
    int *deque;
    int front, rear, size, capacity;

public:
    Deque(int capacity){
        this->capacity = capacity;
        front = -1; 
        rear = 0; size =0;
    }

    bool insertFront(int value){
        if(isFull()) return false;
        if(isEmpty()) front = rear = 0;
        else{
            front = (front - 1 + capacity) % capacity;
            deque[front] = value;
            size++;
        }
        return true;
    }

    bool insertRear(int value){
        if(isFull()) return false;
        if(isEmpty()) front = rear = 0;
        else{
            rear = (rear + 1) % capacity;
            deque[rear] = value;
            size++;
        }
        return true;
    }

    bool deleteFront(){
        if(isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;

        if(isEmpty()) return front = rear = -1;
        return true;
    }

    bool deleteRear(){
        if(isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        if(isEmpty()) return front = rear = -1;
        return true;
    }



    bool isFull(){
        return size == capacity;
    }

    bool isEmpty(){
        return size == 0;
    }
};

int main()
{
    return 0;
}