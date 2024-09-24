#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtBeginning(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data= newData;
    newNode->next = *head;
    *head= newNode;
}
void printList(Node* node)
{
    while (node != nullptr)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"Null"<<endl;
}
int main()
{
    cout<<"***************LAB5*******************"<<endl;
    cout<<"\n";
    Node* head = nullptr;
    insertAtBeginning (&head, 10);
    insertAtBeginning (&head, 20);
    insertAtBeginning (&head, 30);
    cout<<"Linked List"<<endl;
    printList(head);
    return 0;
}