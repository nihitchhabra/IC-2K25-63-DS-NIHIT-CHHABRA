#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

class Queue {
    node *front;
    node *rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void insert();
    void remove_element();
    void display();

    ~Queue() {
        node *temp;
        while (front != NULL) {
            temp = front;
            front = front->link;
            delete temp;
        }
    }
};

void Queue::insert() {
    node *nn = new node();
    if (nn == NULL) {
        cout << "Memory overflow!\n";
        return;
    }
    cout << "Enter data: ";
    cin >> nn->data;
    nn->link = NULL;

    if (front == NULL) {
        front = rear = nn;
    } else {
        rear->link = nn;
        rear = nn;
    }
    cout << "Element inserted successfully.\n";
}

void Queue::remove_element() {
    if (front == NULL) {
        cout << "Queue is empty (Underflow).\n";
    } else {
        node *temp = front;
        cout << "Deleted element: " << front->data << "\n";
        front = front->link;
        
        if (front == NULL) { // If queue becomes empty, reset rear too
            rear = NULL;
        }
        delete temp;
    }
}

void Queue::display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    node *temp = front;
    cout << "Queue elements (Front to Rear): ";
    while (temp != NULL) {
        cout << temp->data << " <- ";
        temp = temp->link;
    }
    cout << "NULL\n";
}

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n--- Queue Using Linked List Menu ---\n";
        cout << "1. Insert (Enqueue)\n2. Delete (Dequeue)\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                q.insert();
                break;
            case 2:
                q.remove_element();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}