#include<iostream>
using namespace std;

#define MAX_SIZE 100

typedef struct Queue{
    int front, rear, size;
    int data[100];
}Queue;

void createQueue(Queue *q){
    q->front = q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue *q){
    if(q->front == q->rear){
        return true;
    }
    return false;
}


bool isFull(Queue *q){
    if((q->rear + 1) % MAX_SIZE == q->front){
        return true;
    }
    return false;
}

void enqueue(Queue *q, int item){
    if(isFull(q)){
        cout<<"Queue is full"<<endl;
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;
    q->size++;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}
int getFontValue(Queue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return q->data[q->front];
}


void display(Queue *q){
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
        return;
    }
    int i = q->front;
    while(i!= q->rear){
        cout<<q->data[i]<<" ";
        i = (i + 1) % MAX_SIZE;
    }
    cout<<q->data[q->rear]<<endl;
}


int main(){
    Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 100);
    enqueue(&q, 110);
    display(&q);
    cout<<"Front value is "<<getFontValue(&q)<<endl;
    dequeue(&q);
    cout<<"Front value is "<<getFontValue(&q)<<endl;
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}