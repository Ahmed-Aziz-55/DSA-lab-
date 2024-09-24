#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next; // pointer to the next node
};
// function to insert node at beginning
void insertAtBeginning(Node** head, int newData)
{
    //Allocate memory for new node
    Node* newNode = new Node();
    //Assign data to new node
    newNode->data= newData;
    //make next of new node point to the current head
    newNode->next = *head;
    //move the head to point to the new node
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
    int value,values;
    cout<<"***************LAB5*******************"<<endl;
    cout<<"\n";
    Node* head = nullptr;
    cout<<"How many values do you want to insert at the beginning of the list"<<endl;
    cin>>value;
    for(int i=0; i<value; i++)
    {
        cout<<"Enter value"<<i+1<<endl;
        cin>>values;
        insertAtBeginning (&head, values);
    }
    cout<<"Linked List"<<endl;
    printList(head);
    return 0;
}