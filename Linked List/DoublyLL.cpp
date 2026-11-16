#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

class DLL {
    node *start;
public:
    DLL() {
        start = NULL;
    }

    void create();
    void display();
    void rev_display();
    void insert(int pos, int val);
    void count();
    void search(int num);
    void delete_e(int d);
    void reverse();

    ~DLL() {
        node *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }
};

void DLL::create() {
    char c;
    do {
        node *nn = new node();
        cout << "Enter Data: ";
        cin >> nn->data;
        nn->next = NULL;
        nn->prev = NULL;

        if (start == NULL) {
            start = nn;
        } else {
            node *temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
        }

        cout << "Do you want to insert more elements? (y/n): ";
        cin >> c;
    } while (c == 'Y' || c == 'y');
}

void DLL::display(){
    if (start == NULL) {
        cout << "Empty list\n";
        return;
    }
    
    node *temp = start;
    cout << "Forward Display: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void DLL::rev_display() {
    if (start == NULL) {
        cout << "Empty list\n";
        return;
    }
    
    node *temp = start;
    cout << "Reverse Display: ";
    while (temp->next != NULL) {
        temp = temp->next;
    }
    cout << "Display in reverse: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

void DLL::insert(int pos, int val) {
    node *nn = new node();
    nn->data = val;
    nn->prev = NULL;
    nn->next = NULL;

    if (pos == 1 || start == NULL) {
        nn->next = start;
        if (start != NULL) {
            start->prev = nn;
        }
        start = nn;
        cout << "Element inserted successfully.\n";
    } else {
        node *temp = start;
        int i = 1;
        while (i < (pos - 1) && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        nn->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = nn;
        }
        temp->next = nn;
        nn->prev = temp;
        cout << "Element inserted successfully.\n";
    }
}

void DLL::count() {
    int i = 0;
    node *temp = start;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    cout << "Total elements: " << i << "\n";
}

void DLL::search(int num) {
    node *temp = start;
    int found = 0;
    int i = 0;

    while (temp != NULL) {
        i++;
        if (temp->data == num) {
            found = 1;
            cout << "Element found at position " << i << "\n";
            break;
        }
        temp = temp->next;
    }

    if (found == 0) {
        cout << "Element not found.\n";
    }
}

void DLL::delete_e(int d) {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node *temp = start;

    if (temp->next == NULL && temp->data == d) {
        start = NULL;
        delete temp;
        cout << "Element deleted.\n";
        return;
    }

    while (temp != NULL) {
        if (temp->data != d) {
            temp = temp->next;
        } else {
            break;
        }
    }

    if (temp == NULL) {
        cout << "Element not found.\n";
    } else {
        if (temp == start) {
            start = start->next;
            start->prev = NULL;
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
        }
        delete temp;
        cout << "Element deleted.\n";
    }
}

// Function from your notes for reversing a Doubly Linked List
void DLL::reverse() {
    node *temp = NULL;
    node *current_node = start;

    while (current_node != NULL) {
        temp = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = temp;
        current_node = current_node->prev; 
    }

    if (temp != NULL) {
        start = temp->prev;
    }
    cout << "List reversed successfully.\n";
}

int main() {
    DLL list;
    int choice, pos, val, num;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Count\n5. Search\n6. Delete\n7. Reverse\n8. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                list.create();
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insert(pos, val);
                break;
            case 4:
                list.count();
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> num;
                list.search(num);
                break;
            case 6:
                cout << "Enter element to delete: ";
                cin >> num;
                list.delete_e(num);
                break;
            case 7:
                list.reverse();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}