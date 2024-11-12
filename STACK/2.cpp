#include <iostream>
using namespace std;

class Stack {
public:
    int* arr;
    int top;
    int size;

    // Constructor
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    void push(int data) {
        if (size - top > 1) {
            top++;
            arr[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        } else {
            top--;
        }
    }

    int gettop() {
        if (top == -1) {
            cout << "No element in stack" << endl;
            return -1; 
        } else {
            return arr[top];
        }
    }

    int getsize() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s(5);  
    s.push(30);
    s.push(40);
    s.push(45);

    cout << "Top element is: " << s.gettop() << endl;
    cout << "Stack size is: " << s.getsize() << endl;

    s.pop();
    cout << "Top element after pop: " << s.gettop() << endl;

    return 0;
}
