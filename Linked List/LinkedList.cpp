#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

class LL {
    node *start;
public:
    LL() {
        start = NULL;
    }

    void create();
    void display();
    void insert(int pos, int val);
    void count();
    void search(int num);
    void delete_e();

    ~LL() {
        node *t;
        while (start != NULL) {
            t = start;
            start = start->link;
            delete t;
        }
    }
};

void LL::create() {
    node *on = NULL;
    char c;
    do {
        node *nn = new node();
        cout << "Enter data: ";
        cin >> nn->data;
        nn->link = NULL;

        if (start == NULL) {
            start = nn;
        } else {
            on->link = nn;
        }
        on = nn;

        cout << "Want to add more data? (y/n): ";
        cin >> c;
    } while (c == 'Y' || c == 'y');
}

void LL::display() {
    node *temp;
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    for (temp = start; temp != NULL; temp = temp->link) {
        cout << temp->data << " -> ";
    }
    cout << "NULL\n";
}

void LL::insert(int pos, int val) {
    node *nn = new node();
    nn->data = val;
    nn->link = NULL;

    if (pos == 1 || start == NULL) {
        nn->link = start;
        start = nn;
        cout << "Element inserted successfully.\n";
    } else {
        node *temp = start;
        int i = 1;
        while (i < (pos - 1) && temp->link != NULL) {
            temp = temp->link;
            i++;
        }
        nn->link = temp->link;
        temp->link = nn;
        cout << "Element inserted successfully.\n";
    }
}

void LL::count() {
    int i = 0;
    node *temp = start;
    if (start == NULL) {
        cout << "List has no elements.\n";
        return;
    }
    while (temp != NULL) {
        temp = temp->link;
        i++;
    }
    cout << "Total elements: " << i << "\n";
}

void LL::search(int num) {
    node *temp = start;
    int found = 0;
    int i = 0;

    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }

    while (temp != NULL) {
        i++;
        if (temp->data == num) {
            found = 1;
            cout << "Element found at position " << i << "\n";
            break;
        }
        temp = temp->link;
    }

    if (found == 0) {
        cout << "Element not found.\n";
    }
}

void LL::delete_e() {
    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node *temp = start;
    node *prev = NULL;
    int num;

    cout << "Enter element to delete: ";
    cin >> num;

    while (temp != NULL) {
        if (temp->data != num) {
            prev = temp;
            temp = temp->link;
        } else {
            break;
        }
    }

    if (temp == NULL) {
        cout << "Data not found.\n";
    } else {
        if (temp == start) {
            start = start->link;
        } else {
            prev->link = temp->link;
        }
        delete temp;
        cout << "Element deleted successfully.\n";
    }
}

int main() {
    LL list;
    int choice, pos, val, num;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Count\n5. Search\n6. Delete\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                list.delete_e();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}