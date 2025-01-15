#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    
    struct node* next;
};

typedef struct node* nodeptr;

nodeptr getNode(){
    nodeptr new_node = (nodeptr)malloc(sizeof(struct node));
    return new_node;
}


struct Linklist{
    nodeptr head;
};

void addFront(struct Linklist* list, int data){
    nodeptr new_node = getNode();
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void deleteFront(struct Linklist* list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    nodeptr temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void displayList(struct Linklist* list){
    nodeptr temp = list->head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;        
    }
    printf("\n");
}


__int32_t main(){
    struct Linklist list; list.head = NULL;

    addFront(&list, 5);
    addFront(&list, 10);
    addFront(&list, 15);

    displayList(&list);

    deleteFront(&list);
    displayList(&list);

}