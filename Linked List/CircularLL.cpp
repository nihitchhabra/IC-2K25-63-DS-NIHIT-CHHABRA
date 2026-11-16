#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class Circular_LL {
    node *start;
public:
    Circular_LL() {
        start = NULL;
    }

    void create();
    void display();
    void insert(int pos, int val);
    void count();
    void search(int num);
    void delete_e(int num);
    void sort();

    ~Circular_LL() {
        if (start == NULL) return;
        node *current = start;
        node *next_node = NULL;
        
        do {
            next_node = current->next;
            delete current;
            current = next_node;
        } while (current != start);
        start = NULL;
    }
};

void Circular_LL::create() {
    char c;
    node *on = NULL;
    do {
        node *nn = new node();
        cout << "Enter value: ";
        cin >> nn->data;
        nn->next = NULL;

        if (start == NULL) {
            start = nn;
            nn->next = start;
        } else {
            on->next = nn;
            nn->next = start;
        }
        on = nn;

        cout << "Add more data? (y/n): ";
        cin >> c;
    } while (c == 'Y' || c == 'y');
}

void Circular_LL::display() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node *temp = start;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != start);
    cout << "(back to start)\n";
}

void Circular_LL::insert(int pos, int val) {
    node *nn = new node();
    nn->data = val;
    nn->next = NULL;

    if (start == NULL) {
        start = nn;
        nn->next = start;
        cout << "Element inserted successfully.\n";
        return;
    }

    if (pos == 1) {
        node *last = start;
        while (last->next != start) {
            last = last->next;
        }
        nn->next = start;
        start = nn;
        last->next = start;
        cout << "Element inserted successfully.\n";
        return;
    }

    node *temp = start;
    int i = 1;
    while (i < pos - 1 && temp->next != start) {
        temp = temp->next;
        i++;
    }
    nn->next = temp->next;
    temp->next = nn;
    cout << "Element inserted successfully.\n";
}

void Circular_LL::count() {
    if (start == NULL) {
        cout << "Total elements: 0\n";
        return;
    }
    int i = 0;
    node *temp = start;
    do {
        i++;
        temp = temp->next;
    } while (temp != start);
    cout << "Total elements: " << i << "\n";
}

void Circular_LL::search(int num) {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node *temp = start;
    int i = 0;
    int found = 0;
    do {
        i++;
        if (temp->data == num) {
            found = 1;
            cout << "Element found at position " << i << "\n";
            break;
        }
        temp = temp->next;
    } while (temp != start);

    if (!found) {
        cout << "Element not found.\n";
    }
}

void Circular_LL::delete_e(int num) {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node *temp = start;
    node *prev = NULL;

    // Case 1: Only one node in the list
    if (start->next == start && start->data == num) {
        delete start;
        start = NULL;
        cout << "Element deleted successfully.\n";
        return;
    }

    // Find the node to delete and its previous node
    node *head = start;
    node *tail = start;
    while (tail->next != start) {
        tail = tail->next;
    }

    do {
        if (head->data == num) {
            if (head == start) {
                start = start->next;
                tail->next = start;
            } else {
                prev->next = head->next;
            }
            delete head;
            cout << "Element deleted successfully.\n";
            return;
        }
        prev = head;
        head = head->next;
    } while (head != start);

    cout << "Element not found for deletion.\n";
}

void Circular_LL::sort() {
    if (start == NULL || start->next == start) {
        return;
    }
    node *i, *j;
    int tempVal;
    i = start;
    do {
        j = i->next;
        do {
            if (i->data > j->data) {
                tempVal = i->data;
                i->data = j->data;
                j->data = tempVal;
            }
            j = j->next;
        } while (j != start);
        i = i->next;
    } while (i != start);
    cout << "List sorted successfully.\n";
}

int main() {
    Circular_LL list;
    int choice, pos, val, num;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Count\n5. Search\n6. Delete\n7. Sort\n8. Exit\n";
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
                list.sort();
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