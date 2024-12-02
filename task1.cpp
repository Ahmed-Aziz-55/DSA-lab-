#include <iostream>
using namespace std;
// Node structure
struct Node {
int data;
Node* next;
};
// Function to insert a new node at the end of the list
void insert(Node*& head, int data) {
Node* newNode = new Node();
newNode->data = data;
newNode->next = nullptr;
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
// Function to delete a node with a specific value
void deleteNode(Node*& head, int key) {
if (head == nullptr) return;
if (head->data == key) {
Node* temp = head;
head = head->next;
delete temp;
return;
}
Node* temp = head;
while (temp->next != nullptr && temp->next->data != key) {
temp = temp->next;
}
if (temp->next == nullptr) {
cout << "Node with value " << key << " not found.\n";
return;
}
Node* nodeToDelete = temp->next;
temp->next = temp->next->next;
delete nodeToDelete;
}
// Function to search for a node with a specific value
bool search(Node* head, int key) {
Node* temp = head;
while (temp != nullptr) {
if (temp->data == key) {
return true;
}
temp = temp->next;
}
return false;
}
// Function to display the linked list
void display(Node* head) {
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL\n";
}
int main() {
    cout<<"Linked List revision"<<endl;
Node* head = nullptr;
int value;
// Create linked list with 5 nodes
cout << "Enter 5 values to create the linked list:\n";
for (int i = 0; i < 5; i++) {
cin >> value;
insert(head, value);
}
cout << "Linked list after insertion: ";
display(head);
// Perform insertion
cout << "\nEnter value to insert at the end: ";
cin >> value;
insert(head, value);
cout << "Linked list after insertion: ";
display(head);
// Perform deletion
cout << "\nEnter value to delete: ";
cin >> value;
deleteNode(head, value);
cout << "Linked list after deletion: ";
display(head);
// Perform search
cout << "\nEnter value to search: ";
cin >> value;
if (search(head, value)) {
cout << "Value " << value << " found in the list.\n";
} else {
cout << "Value " << value << " not found in the list.\n";
}
return 0;
}