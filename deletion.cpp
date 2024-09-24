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
void deleteNode (Node** head, int key)
{
    Node* temp= *head;
    Node* prev = NULL;
    if(temp != NULL && temp->data== key)
    {
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp== NULL)
    {
        cout<<"Value not found  int the list"<<endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void printList(Node* node)
{
    while (node !=NULL)
    {
        cout<< node->data<<"->";
        node= node->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head = NULL;
    int n, value,deleteValue;
    cout<<"How many values do you want to insert in the  list ?";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter value"<<i+1<<endl;
        cin>>value;
        insertAtEnd (&head, value);
    }
    cout<<"The linked list is "<<endl;
    printList(head);
    cout<<"Enter the values of the node to be deleted: "<<endl;
    cin>>deleteValue;
    deleteNode(&head, deleteValue);
    cout<<"The linked list after deletion is: "<<endl;
     cout<<"Linked List"<<endl;
    printList(head);
    return 0;
}