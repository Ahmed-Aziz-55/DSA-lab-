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
// Function to insert a node at the beginning of the circular linked list
void insertBeginning(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (*head == NULL) {
        // If the list is empty, the new node points to itself and becomes the head
        *head = newNode;
        newNode->next = *head;
    } else {
        // If the list is not empty, find the last node
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        // The new node's next points to the current head
        newNode->next = *head;
        // The last node now points to the new node
        temp->next = newNode;
        // Update head to the new node
        *head = newNode;
    }
}

// Function to delete a node from the circular linked list by value
void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = *head;
    Node* previous = NULL;

    // Check if the node to be deleted is the head node
    if (current->data == value) {
        // If there's only one node
        if (current->next == *head) {
            delete current;
            *head = NULL; // List becomes empty
            return;
        } else {
            // Find the last node to update its next pointer
            while (current->next != *head) {
                current = current->next;
            }
            current->next = (*head)->next; // Bypass the head node
            delete *head; // Delete head node
            *head = current->next; // Update head to the next node
            return;
        }
    }

    previous = *head;
    current = previous->next;

    // Traverse the list to find the node to delete
    while (current != *head) {
        if (current->data == value) {
            previous->next = current->next; // Bypass the node to delete
            delete current; // Free memory
            return;
        }
        previous = current;
        current = current->next;
    }

    cout << "Value " << value << " not found in the list." << endl;
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
    cout << "Enter the number of nodes you want to insert at the end: ";
    cin >> n;
    // Insert each node into the circular linked list at the end
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertEnd(&head, value);
    }
    // Traverse and print the circular linked list
    cout << "Elements in the circular linked list after insertion at the end: ";
    traverseList(head);
    // Insert a node at the beginning
    cout << "Enter value to insert at the beginning: ";
    cin >> value;
    insertBeginning(&head, value);
    // Traverse and print the circular linked list after insertion at the beginning
    cout << "Elements in the circular linked list after insertion at the beginning: ";
    traverseList(head);
    // Deleting a node by value
    cout << "Enter value to delete from the list: ";
    cin >> value;
    deleteNode(&head, value);
    // Traverse and print the circular linked list after deletion
    cout << "Elements in the circular linked list after deletion: ";
    traverseList(head);
    deleteList(&head);
    return 0;
}
