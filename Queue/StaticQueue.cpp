#include <iostream>

using namespace std;

class Queue {
    int front, rear, capacity;
    int* arr;

public:
    Queue(int c) {
        capacity = c;
        front = rear = 0;
        arr = new int[capacity];
    }

    void enqueue(int data) {
        if (capacity == rear) {
            return;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue() {
        if (front == rear) {
            return;
        } else {
            for (int i = 0; i < rear - 1; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }

    void display() {
        if (front == rear) {
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.display();
    return 0;
}