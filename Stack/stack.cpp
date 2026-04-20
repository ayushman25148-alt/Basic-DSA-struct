// Stack - Array-based and Linked List-based Implementation
#include <iostream>
#include <stdexcept>
using namespace std;

// --- Array-based Stack ---
class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size = 100) : top(-1), capacity(size) {
        arr = new int[capacity];
    }

    void push(int val) {
        if (top == capacity - 1)
            throw overflow_error("Stack Overflow");
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty())
            throw underflow_error("Stack Underflow");
        return arr[top--];
    }

    int peek() {
        if (isEmpty())
            throw underflow_error("Stack is empty");
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    int size() { return top + 1; }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~ArrayStack() { delete[] arr; }
};

// --- Linked List-based Stack ---
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
private:
    StackNode* top;
    int count;

public:
    LinkedStack() : top(nullptr), count(0) {}

    void push(int val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty())
            throw underflow_error("Stack Underflow");
        StackNode* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        count--;
        return val;
    }

    int peek() {
        if (isEmpty())
            throw underflow_error("Stack is empty");
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    int size() { return count; }

    void display() {
        StackNode* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedStack() {
        while (top) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    cout << "=== Array-based Stack ===" << endl;
    ArrayStack aStack;
    aStack.push(10);
    aStack.push(20);
    aStack.push(30);
    cout << "Stack (top to bottom): ";
    aStack.display();
    cout << "Peek: " << aStack.peek() << endl;
    cout << "Pop: " << aStack.pop() << endl;
    cout << "Stack after pop: ";
    aStack.display();

    cout << "\n=== Linked List-based Stack ===" << endl;
    LinkedStack lStack;
    lStack.push(10);
    lStack.push(20);
    lStack.push(30);
    cout << "Stack (top to bottom): ";
    lStack.display();
    cout << "Peek: " << lStack.peek() << endl;
    cout << "Pop: " << lStack.pop() << endl;
    cout << "Stack after pop: ";
    lStack.display();

    return 0;
}
