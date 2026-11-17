#include <iostream>

using namespace std;

class Deque {
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Deque(int s) {
        size = s;
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) return;
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = size - 1;
        else
            front = front - 1;
        arr[front] = key;
    }

    void insertRear(int key) {
        if (isFull()) return;
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;
        arr[rear] = key;
    }

    void deleteFront() {
        if (isEmpty()) return;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    void deleteRear() {
        if (isEmpty()) return;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(5);
    dq.insertRear(10);
    dq.insertFront(2);
    dq.display();
    return 0;
}