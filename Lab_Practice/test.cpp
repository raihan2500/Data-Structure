#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

typedef struct Node* nodeptr;

void display(nodeptr ptr){
    if(ptr == NULL){
        cout<<"Empty list\n";
    }
    
    else{
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->link;
        }
        cout<<endl;
    }
}

void sortList(nodeptr head){

    nodeptr current = head;

    if(current == NULL){
        cout<<"List is Empty\n";
    }
    else{
        nodeptr ptr = NULL;
        while(current != NULL){
            ptr = current->link;
            int temp;
            while(ptr != NULL){
                if(ptr->data < current->data){
                    temp = current->data;
                    current->data = ptr->data;
                    ptr->data = temp;        
                }
                ptr = ptr->link;
            }
            current = current->link;
        }
    }
}

bool addNumber(nodeptr head, int num){

    nodeptr ptr = head;
    nodeptr temp;
    if(ptr == NULL){
        return false;
    }
    
        nodeptr newNode = (nodeptr)malloc(sizeof(nodeptr));
        newNode->data = num;
        newNode->link = NULL;
        while(ptr != NULL){
            if(ptr->link->data > num){
                temp = ptr->link;
                break;
            }      
            ptr=ptr->link;
        }
        ptr->link = newNode;
        newNode->link= temp;

    return true;

}

bool AddtoPosition(nodeptr head, int num, int pos){
   
    nodeptr ptr = head;
    if(ptr == NULL){
        return false;
    }
    printf("Adding %d at %dth position\n", num, pos);
   
    
    nodeptr temp = (nodeptr)malloc(sizeof(nodeptr));
    temp->data = num;
    temp->link = NULL;
    
    int i = 1;

    while(i < (pos-1)){
        ptr = ptr->link;
        i++;
    }
    
    temp->link = ptr->link;
    ptr->link = temp;
    return true;
    
}

int main(){

    cout<<"Enter size of the list\n";
    
    int size;
    cin>>size;

    cout<<"Enter elements of the list\n";

    int first;
    cin>>first;

    nodeptr head = (nodeptr)malloc(sizeof(nodeptr));
    head->data = first;
    head->link = NULL;

    nodeptr ptr = head;
    size--;

    while(size--){
        int x;
        cin>>x;

        nodeptr current = (nodeptr)malloc(sizeof(nodeptr));
        current->data = x;
        current->link = NULL;

        ptr->link = current;
        ptr = ptr->link;
    }
    cout<<"\tEnter your command\n\tPress 1 To display List\n\tpress 2 to display sorted list\n\tpress 3 to Add a Number on the existing list\n\tpress 4 to Add a number at specific position\n\tpress 5 to quit the program\n";
    
    int com;
    
    while(1){
        cin>>com;
    switch (com)
    {
    case 1: 
        display(head);
        break;
    case 2:
        sortList(head);
        display(head);
        break;
    case 3:
        cout<<"Enter number to add\n";
        int num;
        cin>>num;
        if(addNumber(head,num) ){
            cout<<"Number added\n";
        }else cout<<"Operation failed\n";
        break;
    
    case 4 :
        cout<<"Enter number and position\n";
        int n, pos;
        cin>>n>>pos;
        if(AddtoPosition(head,n, pos)){
            cout<<"Operation successfull\n";
        }
        else cout<<"Operation failed\n";
        break;
    case 5 :
        cout<<"Good Bye!";
        exit(0);
        break;
    }
    }
    return 0;

}