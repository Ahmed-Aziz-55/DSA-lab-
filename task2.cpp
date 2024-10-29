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

// In-order traversal (Left, Root, Right)
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preOrderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal (Left, Right, Root)
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = nullptr;
    int value, nodeCount;
    cout << "How many nodes do you want to add? ";
    cin >> nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);  // Update root
    }
    cout << "In-Order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Pre-Order traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Post-Order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}
