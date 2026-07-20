#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *next,*prev;
}Node ,*link;

link create(int x){
    link temp=new node;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(link &head,int x){
    link temp=create(x);
    if(head==NULL){
        head=temp;
        return;
    }
    link curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
}
void insertAtBeginning(link &head, int x) {
    link temp = create(x);
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void delete_node(link &head, int x) {
    if (head == NULL) return;
    if (head->data == x) {
        link temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return;
    }
    link curr = head;
    while (curr != NULL) {
        if (curr->data == x) {
            if (curr->prev != NULL) curr->prev->next = curr->next;
            if (curr->next != NULL) curr->next->prev = curr->prev;
            delete curr;
            return;
        }
        curr = curr->next;
    }
}
Node *listsort(Node *head) {
    if (head == NULL || head->next == NULL) return head;
    Node *pivot = head;
    Node *tail = head;
    Node *prev = NULL;
    while (tail->next != NULL) {
        prev = pivot;
        pivot = pivot->next;
        tail = tail->next;
    }
    prev->next = NULL;
    Node *left = listsort(head);
    Node *right = listsort(pivot);
    Node *result = NULL;
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            if (result == NULL) {
                result = left;
                left = left->next;
                result->next = NULL;
            } else {
                result->next = left;
                left = left->next;
                result = result->next;
                result->next = NULL;
            }
        } else {
            if (result == NULL) {
                result = right;
                right = right->next;
                result->next = NULL;
            } else {
                result->next = right;
                right = right->next;
                result = result->next;
                result->next = NULL;
            }
        }
    }
    if (left != NULL) {
        if (result == NULL) {
            result = left;
            left = left->next;
            result->next = NULL;
        } else {
            result->next = left;
            left = left->next;
            result = result->next;
            result->next = NULL;
        }
    }
    if (right != NULL) {
        if (result == NULL) {
            result = right;
            right = right->next;
            result->next = NULL;
        } else {
            result->next = right;
            right = right->next;
            result = result->next;
            result->next = NULL;
        }
    }
    return result;
}
void delete_pos(link &head, int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        link temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return;
    }
    link curr = head;
    int i = 1;
    while (curr != NULL && i < pos) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL) return;
    if (curr->prev != NULL) curr->prev->next = curr->next;
    if (curr->next != NULL) curr->next->prev = curr->prev;
    delete curr;
}

void reverse_list(link &head) {
    link curr = head;
    link prev = NULL;
    link next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display(link head){
    link curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
void reverse(link &head){
    link curr=head;
    link prev=NULL;
    link next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void free_list(link &head){
    link curr=head;
    while(curr!=NULL){
        link temp=curr;
        curr=curr->next;
        delete temp;
    }
    head=NULL;
}
int main(){
    link head=NULL;
    insert(head,1);
    insert(head,7);
    insert(head,6);
    insert(head,4);
    insert(head,2);
    insertAtBeginning(head,0);
    display(head);
    reverse_list(head);
    display(head);
    delete_node(head,2);
    display(head);
    delete_node(head,3);
    display(head);
    delete_pos(head,3);
    display(head);
    free_list(head);
    return 0;
}