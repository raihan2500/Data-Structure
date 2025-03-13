#include<stdio.h>
#include<stdlib.h>



struct Node{
    void *data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node* nodeptr;

nodeptr getNode(void *data){
    nodeptr new_node = (nodeptr) malloc(sizeof(struct Node));
    new_node->next = new_node->prev = NULL;
    new_node->data = data;
    return new_node;
}

struct Vector{
    nodeptr head;
    nodeptr tail;
    
};

void push_front(struct Vector* list, void *data){
    nodeptr new_node = getNode(data);
    if(!list->head){
        list->head = list->tail = new_node;
        return;
    }
    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
}

void push_back(struct Vector* list, void *data){
    nodeptr new_node = getNode(data);
    if(!list->head){
        list->head = list->tail = new_node;
        return;
    }
    list->tail->next = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;
}

void pop_front(struct Vector* list){
    if(!list->head)return;
    nodeptr temp = list->head;
    list->head = list->head->next;
    if(list->head)list->head->prev = NULL;
    free(temp);
}

void pop_back(struct Vector* list){
    if(!list->head)return;
    nodeptr temp = list->tail;
    list->tail = list->tail->prev;
    if(list->tail)list->tail->next = NULL;
    free(temp);
}

void clear(struct Vector* list){
    while(list->head){
        pop_front(list);
    }
}




void display(struct Vector* list){
    nodeptr temp = list->head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


__int32_t main(){
    struct Node obj;
    struct Vector list;
    
    push_back(&list, 5);
    push_back(&list, 10);
    push_back(&list, 15);
    clear(&list);
    display(&list);
    
}