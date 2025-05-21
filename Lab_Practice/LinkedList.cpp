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
    node(int item = 0){
        data = item;
    }
};
typedef node* nodeptr;


void insertBegin(nodeptr &root, int data){
    if(root == NULL){
        root = new node(data);
        return;
    }
    nodeptr new_node = new node(data);
    new_node->next = root;
    root = new_node;
}

void insertEnd(nodeptr &root, int data){
    if(root == NULL){
        root = new node(data);
        return;
    }
    nodeptr it = root;
    while(it->next != NULL)it = it->next;
    nodeptr new_node = new node(data);
    it->next = new_node;
}

void insertIndex(nodeptr &root, int n, int data){
    if(n == 1){
        insertBegin(root, data);
        return;
    }
    nodeptr save = root;
    nodeptr it = save->next;
    int i = 2;

    while(it != NULL){
        if(i == n){
            nodeptr new_node = new node(data);
            save->next = new_node;
            new_node->next = it;
            return;
        }
        i++;
        save = it;
        it = it->next;
    }
    if(i == n){
        nodeptr new_node = new node(data);
        save->next = new_node;
    }
}

void removeBegin(nodeptr &root){
    if(root == NULL)return;
    nodeptr temp = root;
    root = root->next;
    delete(temp);
}

void removeEnd(nodeptr &root){
    nodeptr it = root;
    if(it == NULL or it->next == NULL){
        removeBegin(root);
        return;
    }
    while(it->next->next != NULL){
        it = it->next;
    }
    nodeptr temp = it->next;
    it->next = NULL;
    delete(temp);
}

void traverse(nodeptr root){
    nodeptr it = root;
    while(it != NULL){
        cout << it->data <<" ";
        it = it->next;
    }
    cout << '\n';
}


int32_t main(){
    nodeptr root = NULL;
    insertBegin(root, 5);
    insertBegin(root, 40);
    insertBegin(root, 50);
    insertEnd(root, 12);

    insertIndex(root, 5, 99);
    removeBegin(root);
    removeBegin(root);
    removeEnd(root);
    removeEnd(root);
    traverse(root);
}