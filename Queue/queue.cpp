// Queue - Array-based (Circular) and Linked List-based Implementation
#include <iostream>
#include <stdexcept>
using namespace std;

// --- Circular Array-based Queue ---
class ArrayQueue {
private:
    int* arr;
    int front, rear, count, capacity;

public:
    ArrayQueue(int size = 100) : front(0), rear(-1), count(0), capacity(size) {
        arr = new int[capacity];
    }

    void enqueue(int val) {
        if (isFull())
            throw overflow_error("Queue is Full");
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    int dequeue() {
        if (isEmpty())
            throw underflow_error("Queue is Empty");
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    int frontElement() {
        if (isEmpty())
            throw underflow_error("Queue is Empty");
        return arr[front];
    }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == capacity; }
    int size()     { return count; }

    void display() {
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }

    ~ArrayQueue() { delete[] arr; }
};

// --- Linked List-based Queue ---
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val) : data(val), next(nullptr) {}
};

class LinkedQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;

public:
    LinkedQueue() : front(nullptr), rear(nullptr), count(0) {}

    void enqueue(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty())
            throw underflow_error("Queue is Empty");
        QueueNode* temp = front;
        int val = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        count--;
        return val;
    }

    int frontElement() {
        if (isEmpty())
            throw underflow_error("Queue is Empty");
        return front->data;
    }

    bool isEmpty() { return front == nullptr; }
    int size()     { return count; }

    void display() {
        QueueNode* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedQueue() {
        while (front) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    cout << "=== Array-based Queue ===" << endl;
    ArrayQueue aQueue;
    aQueue.enqueue(10);
    aQueue.enqueue(20);
    aQueue.enqueue(30);
    cout << "Queue (front to rear): ";
    aQueue.display();
    cout << "Front: " << aQueue.frontElement() << endl;
    cout << "Dequeue: " << aQueue.dequeue() << endl;
    cout << "Queue after dequeue: ";
    aQueue.display();

    cout << "\n=== Linked List-based Queue ===" << endl;
    LinkedQueue lQueue;
    lQueue.enqueue(10);
    lQueue.enqueue(20);
    lQueue.enqueue(30);
    cout << "Queue (front to rear): ";
    lQueue.display();
    cout << "Front: " << lQueue.frontElement() << endl;
    cout << "Dequeue: " << lQueue.dequeue() << endl;
    cout << "Queue after dequeue: ";
    lQueue.display();

    return 0;
}
