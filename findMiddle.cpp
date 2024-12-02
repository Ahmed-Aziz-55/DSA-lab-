#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head; // Moves one step at a time
    Node* fast = head; // Moves two steps at a time

    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer points to the middle
}

// Function to add a new node at the end of the linked list
void appendNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    cout<<"\tREVISION"<<endl;
    Node* head = nullptr;

    // Creating a linked list
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    cout << "Linked List: ";
    displayList(head);

    // Find the middle of the linked list
    Node* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "The middle node is: " << middle->data << endl;
    } else {
        cout << "The linked list is empty!" << endl;
    }

    return 0;
}
