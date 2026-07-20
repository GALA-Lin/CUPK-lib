#include<iostream>
using namespace std;

#define MAX_SIZE 100;

typedef struct Stack{
    int top;
    int data[100];
}Stack;

void InitStack(Stack *s){
    s->top=-1;
}

bool isEmpty(Stack *s){
    if(s->top==-1)
        return true;
    else
        return false;
}

bool isFull(Stack *s){
    if(s->top==99)
        return true;
    else
        return false;
}

void push(Stack *s, int x){
    if(isFull(s)){
        cout<<"Stack overflow"<<endl;
        return;
    }
    s->data[++s->top]=x;
}

int pop(Stack *s){
    if(isEmpty(s)){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    return s->data[s->top--];
}

int getTopValue(Stack *s){
    if(isEmpty(s)){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    return s->data[s->top];
}


int main(){
    Stack s;
    InitStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    cout<<"Top element is "<<getTopValue(&s)<<endl;
    pop(&s);
    cout<<"Top element is "<<getTopValue(&s)<<endl;
    return 0;
}