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
void postOrderTraversal(Node* root){
        if(root==nullptr) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
    int main(){
        Node* root=nullptr;
        root=insert(root,50);
        root=insert(root,30);
        root=insert(root,20);
        root=insert(root,40);
        root=insert(root,70);
        root=insert(root,60);
        root=insert(root,80);
        cout<<"Post order traversal of the BST: ";
        postOrderTraversal(root);
        return 0;
    }
