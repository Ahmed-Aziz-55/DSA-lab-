#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next; // pointer to the next node
};
// function to insert node at beginning
void insertAtEnd(Node** head, int newData)
{
    //Allocate memory for new node
    Node* newNode = new Node();
    //Assign data to new node
    newNode->data= newData;
    newNode->next = NULL;
    // if the list is empty, the new node become the head
    if(*head==NULL)
    {
        *head= newNode;
        return;
    }
    Node* last= *head;
    while (last->next !=NULL)
    {
        last= last->next;
    }
    last->next= newNode;
}
void printList(Node* node)
{
    while (node != NULL)
    {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"Null"<<endl;
}
int main()
{
   int value,values;
    cout<<"***************LAB5*******************"<<endl;
   cout<<"\n";
    Node* head = NULL;
   cout<<"How many values do you want to insert at the beginning of the list"<<endl;
   cin>>value;
   for(int i=0; i<value; i++)
    {
        cout<<"Enter value"<<i+1<<endl;
        cin>>values;
        insertAtEnd (&head, values);
    }
    cout<<"Linked List"<<endl;
    printList(head);
    return 0;
}