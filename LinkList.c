#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next, *prev;
};

typedef struct Node* nodeptr;

nodeptr getNode(){
    nodeptr new_node = (nodeptr) malloc(sizeof(struct Node));
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

struct LinkedList{
    nodeptr head;
    nodeptr tail;
};

void addFront(struct LinkedList *list, int data){
    nodeptr new_node = getNode();
    new_node->data = data;
    
    if(!list->head){
        list->head = list->tail = new_node;
        return;
    }
    list->head->prev = new_node;
    new_node->next = list->head;
    list->head = new_node;
}

void addBack(struct LinkedList *list, int data){
    nodeptr new_node = getNode();
    new_node->data = data;
    if(list->tail == NULL){
        list->head = list->tail = new_node;
        return;
    }
    
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
}

void deleteFront(struct LinkedList *list){
    if(list->head == NULL)return;
    nodeptr temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
}

void deleteBack(struct LinkedList *list){
    if(list->tail == NULL)return;
    nodeptr temp = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);
}

void display(struct LinkedList *list){
    nodeptr temp = list->head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

__int32_t main(){
    struct LinkedList list;
    addFront(&list, 5);
    addFront(&list, 10);
    display(&list);

    addBack(&list, 15);
    addFront(&list, 7);
    display(&list);

    deleteFront(&list);
    display(&list);
    
    deleteBack(&list);
    display(&list);
}