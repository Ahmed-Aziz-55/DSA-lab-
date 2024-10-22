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

// Function to perform in-order traversal and store the sorted elements in an array
void inOrderTraversal(Node* root, int sortedArray[], int &index) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, sortedArray, index);   // Traverse left subtree
    sortedArray[index++] = root->data;                  // Store root's data in the array
    inOrderTraversal(root->right, sortedArray, index);  // Traverse right subtree
}

// Function to sort an array using BST
void bstSort(int arr[], int size) {
    Node* root = nullptr;


    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    inOrderTraversal(root, arr, index);
}
int main() {

    int arr[] = {10, 3, 7, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using BST
    bstSort(arr, size);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
