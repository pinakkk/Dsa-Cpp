#include <iostream>
using namespace std;

class Queue{
public:
    int *arr;
    int front, rear, size;

    Queue(int d){
        this->size = d;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int element){
        if (rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int dequeue(){
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int gfront(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        return front==rear;
    }
};

class CircularQueue{
    public:
    int *arr, size, front, rear;

    CircularQueue(int n){
        size = 101;
        arr = new int[size];
        front = rear = 0;
    }

    bool enqueue(int value){
        if(front == 0 && rear == size -1 || (rear = (front-1) % (size-1))){
            cout << "Queue is Full!";
            return false;
        } 
        else if(front == -1){ // first element
            front = rear = 0;
            // arr[rear] = value;
        }
        else if(rear == -1 && front != 0){ // to maintain cyclic
            rear = 0; 
            // arr[rear] = value;
        }
        else{ // normal
            rear++;
            // arr[rear] = value;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue(){
        if(front == -1){
            cout << "Queue is empty";
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ // single element is present 
            front = rear = -1;
        }
        else if(front == -1) {// at the last now maintain cyclic
            front = 0;
        }
        else{ // normal
            front++;
        }
        return ans;
    }

};

int main(){
    Queue q(5);
    q.enqueue(5);
    q.enqueue(20);

    while(!q.isEmpty()){
        cout << q.gfront() << " ";
        q.dequeue();
    }


    return 0;
}