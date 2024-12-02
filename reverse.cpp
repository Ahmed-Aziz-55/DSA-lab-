#include <iostream>
using namespace std;
// Node structure for the singly linked list
struct Node {
int data;
Node* next;
};
// Function to reverse the linked list
Node* reverseList(Node* head) {
Node* prev = nullptr; 
Node* current = head; 
Node* next = nullptr; 
while (current != nullptr) {
next = current->next; 
current->next = prev; 
prev = current;
current = next;
}
head = prev; 
return head;
}
void push(Node** head_ref, int new_data) {
Node* new_node = new Node(); // Allocate new node
new_node->data = new_data; // Put in the data
new_node->next = (*head_ref); // Link the old list to the new node
(*head_ref) = new_node; // Move the head to point to the new node
}
void printList(Node* node) {
while (node != nullptr) {
cout << node->data << " ";
node = node->next;
}
cout << endl;
}
int main() {
    cout<<"LINKED LIST REVISION "<<endl;
Node* head = nullptr; 
push(&head, 1);
push(&head, 2);
push(&head, 3);
push(&head, 4);
push(&head, 5);
cout << "Original Linked List: " << endl;
printList(head);
head = reverseList(head);
cout << "Reversed Linked List: " << endl;
printList(head);
return 0;
}