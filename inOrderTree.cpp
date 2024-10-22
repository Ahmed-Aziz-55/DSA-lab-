#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->left=newNode->right=nullptr;
    return newNode;
}
Node* insert(Node* root, int value){
    if(root==nullptr){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
void inOrderTraversal(Node* root){
        if(root==nullptr) return;
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    int main(){
        Node* root=nullptr;
        int value,node;
        cout<<"How many node do you want to add"<<endl;
        cin>>node;
        for(int i=0;i<node;i++){
            cout<<"Enter Values "<<i+1<<endl;
            cin>>value;
            insert(root,value); 
        }  
        cout<<"In-Order traversal of the BST: ";
        inOrderTraversal(root);
        return 0;
    }
