#include <iostream>

using namespace std;


struct node{
    int data;
    struct node *left,*right;
};

void preorder(struct node *root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

struct node* create(){
    struct node *newnode;
    int x;
    newnode=(struct node *) malloc(sizeof(struct node));
    cout<<"Enter the value of the data / -1 for no node"<<endl;
    cin>>x;
    if(x==-1)
    return NULL;
    newnode->data=x;
    cout<<"Enter the left child of "<<x<<endl;
    newnode->left=create();
    cout<<"Enter the right child of "<<x<<endl;
    newnode->right=create();
    return newnode;
}



int main() {
    struct node *root;
    root=create();
    cout<<"Preorder Traversal of given binary tree is:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal of given binary tree is:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal of given binary tree is:"<<endl;
    postorder(root);
}
