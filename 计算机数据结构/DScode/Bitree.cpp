#include<iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node* &root, int data){
    if(root == NULL){
        root = createNode(data);
        return;
    }
    if(data < root->data){
        if(root->left == NULL){
            root->left = createNode(data);
        }
        else{
            insert(root->left, data);
        }
    }
    else{
        if(root->right == NULL){
            root->right = createNode(data);
        }
        else{
            insert(root->right, data);
        }
    }
}


void inorder(node* root){
    if(root!= NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node* root){
    if(root!= NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void find(node* root, int data){
    if(root == NULL){
        cout<<"Element not found"<<endl;
        return;
    }
    if(root->data == data){
        cout<<"Element found"<<endl;
        return;
    }
    if(data < root->data){
        find(root->left, data);
    }
    else{
        find(root->right, data);
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    int data;
    node* root = NULL;
    while (true) {
        cin >> data;
        if (data == -1) {
            break;
        }
        insert(root, data);
    }

    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;

    int search_data;
    cout<<"Enter the element to search: ";
    cin>>search_data;
    find(root, search_data);


    cout<<"Tree height: "<<height(root)<<endl;

    return 0;
}