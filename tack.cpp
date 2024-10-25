#include <iostream>
using namespace std;

class TwoStack {
    int *arr, size, top1, top2;

public:
    TwoStack(int d) {
        size = d;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = element;
        } else {
            cout << "Stack Overflow in Stack 1" << endl;
        }
    }

    void push2(int element) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = element;
        } else {
            cout << "Stack Overflow in Stack 2" << endl;
        }
    }

    void pop1() {
        if (top1 >= 0) {
            cout << "Popped from Stack 1: " << arr[top1] << endl;
            top1--;
        } else {
            cout << "Stack Underflow in Stack 1" << endl;
        }
    }

    void pop2() {
        if (top2 < size) {
            cout << "Popped from Stack 2: " << arr[top2] << endl;
            top2++;
        } else {
            cout << "Stack Underflow in Stack 2" << endl;
        }
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == size;
    }

    bool isFull1() {
        return top2 - top1 == 1;  // Stack 1 is full if there's no space between top1 and top2
    }

    bool isFull2() {
        return top2 - top1 == 1;  // Stack 2 is full if there's no space between top1 and top2
    }

    int issize(){
        return top1;
    }
};

int main() {
    TwoStack ts(5);

    cout << "Stack 1 empty: " << ts.isEmpty1() << endl;
    cout << "Stack 2 empty: " << ts.isEmpty2() << endl;

    ts.push1(10);
    ts.push2(20);

    cout << "Stack 1 full: " << ts.isFull1() << endl;
    cout << "Stack 2 full: " << ts.isFull2() << endl;

    ts.push1(15);
    ts.push1(30); // Push another element to fill Stack 1

    cout << "Stack 1 full: " << ts.isFull1() << endl;

    ts.pop1();
    ts.pop2();

    cout << "Stack 1 full: " << ts.isFull1() << endl;
    cout << "Stack 2 full: " << ts.isFull2() << endl;

    return 0;
}
