#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int value, nodeCount;

    cout << "How many nodes do you want to add? ";
    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);  // Update the root with the returned tree
    }

    cout << "In-Order traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
