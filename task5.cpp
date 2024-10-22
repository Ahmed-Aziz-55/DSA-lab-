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

    // Predefined array to construct the BST
    int arr[] = {10, 3, 7, 1, 9, 15, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Insert elements into the BST
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    cout << "In-Order traversal (Left, Root, Right): ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-Order traversal (Root, Left, Right): ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-Order traversal (Left, Right, Root): ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
