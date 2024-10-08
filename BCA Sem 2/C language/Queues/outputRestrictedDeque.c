#include <stdio.h>

// 2) Output-Restricted Deque: This type of deque allows insertion from both ends, 
// namely the front and the rear. However, deletion is restricted to only the rear end.


int front = -1, rear = -1;

void insertionOutputResDeque(int queue[], int size, int element, char choice){
    if(front == (rear+1)%size){
        printf("Queue Overflow\n");
        return;
    }else{
        if(rear == -1){
            rear = 0; front = 0;
        }else if(choice == 'f'){
            front = (front-1+size)%size;
        }else if(choice == 'r'){
            rear = (rear+1)%size;
        }else{
            printf("Invalid Input");
            return;
        }
        queue[choice == 'f' ? front : rear] = element;
    }
}

void delOutputResDeque(int queue[],int size){
    if(front == -1 && rear == -1){
        printf("Queue underflow\n");
        return;
    }else{
        if(front == rear){
            front = -1; rear = -1;
        }else{
            front = (front+1)%size;
        }
    }
}

void printDeque(int deque[],int size){
    printf("Deque Elements: ");
    if(front == -1 && rear ==-1){
        printf("Deque Underflow\n");
        return;
    }
    for(int i = front; i!= rear; i = (i+1) % size){
        printf("%d ",deque[i]);
    }
    printf("%d\n",deque[rear]); // last element
}

void main(){
    int n = 5;
    int queue[n];

    insertionOutputResDeque(queue,n,10,'f');
    insertionOutputResDeque(queue,n,20,'r');
    insertionOutputResDeque(queue,n,30,'f');
    insertionOutputResDeque(queue,n,40,'r');
    insertionOutputResDeque(queue,n,50,'f');

    printDeque(queue,n);
}






