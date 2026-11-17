#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (root->data < key) return search(root->right, key);
    return search(root->left, key);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (search(root, 40) != nullptr)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}