#include<stdio.h>

int queue[100];
int n = 10, front = 0, rear = 0;

void add(int item){
    if((front == 1 && rear == n) || front == rear + 1){
        printf("Overflow\n");
        return;
    }
    if(front == 0){
        front = 1; rear = 1;
    }else{
        rear++;
    }
    queue[rear] = item;
}

int delete(){
    if(front == 0){
        printf("Underflow\n");
        return 0;
    }
    int item = queue[front];
    if(front == rear){
        front = rear = 0;
    }else if(front == n)front = 1;
    else front++;
    return item;    
}

int main(){
    add(5);
    add(3);
    add(7);
    add(6);
    
    int item = delete();
    while(item){
        printf("%d ", item);
        item = delete();
    }
}