#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        root = new Node();
        root->data = value;
        root->left = root->right = nullptr;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;  // Value not found
    }
    if (root->data == value) {
        return true;  // Value found
    } else if (value < root->data) {
        return search(root->left, value);  // Search in the left subtree
    } else {
        return search(root->right, value);  // Search in the right subtree
    }
}

int main() {
    Node* root = nullptr;
    int nodeCount, value, searchValue;

    cout << "How many nodes do you want to add? ";
    cin >> nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }
    cout << "Enter the value you want to search for: ";
    cin >> searchValue;
    if (search(root, searchValue)) {
        cout << searchValue << " is found in the BST." << endl;
    } else {
        cout << searchValue << " is not found in the BST." << endl;
    }

    return 0;
}
