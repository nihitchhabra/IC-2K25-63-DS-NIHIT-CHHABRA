#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};  

class L_stack {
    node *top;
public:
    L_stack() {
        top = NULL;
    }

    void push();
    void pop();
    void display();

    ~L_stack() {
        node *temp;
        while (top != NULL) {
            temp = top;
            top = top->link;
            delete temp;
        }
    }
};

void L_stack::push() {
    node *nn = new node();
    if (nn == NULL) {
        cout << "Memory is full (Heap overflow).\n";
    } else {
        cout << "Enter data: ";
        cin >> nn->data;
        nn->link = top;
        top = nn;
        cout << "Element pushed successfully.\n";
    }
}

void L_stack::pop() {
    if (top == NULL) {
        cout << "Stack is empty (Underflow).\n";
    } else {
        cout << "Deleted element: " << top->data << "\n";
        node *temp = top;
        top = top->link;
        delete temp;
    }
}

void L_stack::display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    node *temp = top;
    cout << "Stack elements (Top to Bottom):\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->link;
    }
}

int main() {
    L_stack s;
    int choice;

    do {
        cout << "\n--- Stack Using Linked List Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
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