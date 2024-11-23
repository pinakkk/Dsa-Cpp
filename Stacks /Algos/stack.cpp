#include <iostream>
using namespace std;

class Stack {
private:
    int arr[1000];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top >= 999) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return top < 0; }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;  // Output: 30
    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;  // Output: 20

    return 0;
}
