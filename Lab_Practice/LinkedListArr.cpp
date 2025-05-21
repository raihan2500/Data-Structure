#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct node{
    int data;
    node *next = NULL;
    node(int data = 0){
        this->data = data;
    };
};

typedef node* nodeptr;

struct LinkedList{
    nodeptr root = NULL;

    void insBeg(int data){
        if(root == NULL){
            root = (nodeptr)malloc(sizeof(nodeptr));
            root->data = data;
            return;
        }
        nodeptr new_node = (nodeptr)malloc(sizeof(nodeptr));
        new_node->data = data;
        new_node->next = root;
        root = new_node;
    }
    void insEnd(int data){
        if(root == NULL){
            root = (nodeptr)malloc(sizeof(nodeptr));
            root->data = data;
            return;
        }
        nodeptr ptr = root;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        nodeptr new_node = (nodeptr)malloc(sizeof(nodeptr));
        new_node->data = data;
        ptr->next = new_node;
    }

    void remBeg(){
        if(root == NULL){
            cout << "Underflow\n";
            return;
        }
        nodeptr temp = root;
        root = root->next;
        free(temp);
    }
    void remEnd(){
        if(root == NULL){
            cout << "Underflow\n";
            return;
        }
        if(root->next == NULL){
            remBeg();
            return;
        }
        nodeptr save = root;
        nodeptr ptr = root->next;

        while(ptr->next != NULL){
            save = ptr;
            ptr = ptr->next;
        }
        save->next = NULL;
        free(ptr);
    }

    void display(){
        nodeptr ptr = root;
        while(ptr != NULL){
            cout << ptr->data <<" ";
            ptr = ptr->next;
        }
        cout << '\n';
    }
};

int32_t main(){
    LinkedList ls, ls2;
    ls.insBeg(5);
    ls.insBeg(6);
    ls.insBeg(7);
    
    ls.insEnd(10);
    ls.insEnd(11);
    ls.insEnd(12);

    ls.display();

    ls.remBeg();
    ls.display();
    

    ls.remEnd();
    ls.display();

    ls2.insBeg(55);
    ls2.insBeg(66);
    ls2.insBeg(77);

    nodeptr ptr = ls.root;
    while(ptr->next != NULL)ptr = ptr->next;
    ptr->next = ls2.root;

    ls.display();
}