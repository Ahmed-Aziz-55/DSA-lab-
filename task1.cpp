#include <iostream>
using namespace std;
// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};
// Function to insert a node at the end of the circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*head == NULL) {
        // If the list is empty, the new node points to itself and becomes the head
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse to the last node (which points to head)
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // The new node points back to head, maintaining circular structure
    }
}
// Function to traverse and print the elements of the circular linked list
void traverseList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    // We use a do-while loop to ensure we print the first node's data before checking if we are back at the head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
// Function to free up the memory of the circular linked list
void deleteList(Node** head) {
    if (*head == NULL)
        return;
    Node *current = *head, *nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != *head);
    *head = NULL; // Set head to NULL after deletion
}
int main() {
    Node* head = NULL; // Initialize the head to NULL
    int n, value;
    // Take input from the user for number of nodes
    cout << "Enter the number of nodes you want to insert: ";
    cin >> n;
    // Insert each node into the circular linked list
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertEnd(&head, value);
    }
    // Traverse and print the circular linked list
    cout << "Elements in the circular linked list: ";
    traverseList(head);
    // Clean up memory after the program is done
    deleteList(&head);
    return 0;
}
