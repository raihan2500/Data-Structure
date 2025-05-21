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
    node *left = NULL;
    node *right = NULL;
    node(int data = 0){
        this->data = data;
    }
};

typedef node* nodeptr;

struct BST{
    nodeptr root = NULL;
    
    void addData(nodeptr ptr, int &data){
        if(ptr->data > data){
            if(ptr->left != NULL){
                addData(ptr->left, data);
            }else{
                nodeptr new_node = (nodeptr)malloc(sizeof(nodeptr));
                new_node->data = data;
                ptr->left = new_node; 
            }
        }else{
            if(ptr->right != NULL){
                addData(ptr->right, data);
            }else{
                nodeptr new_node = (nodeptr)malloc(sizeof(nodeptr));
                new_node->data = data;
                ptr->right = new_node;
            }
        }
    }

    void add(int data){
        if(root == NULL){
            root = (nodeptr)malloc(sizeof(nodeptr));
            root->data = data;
            return;
        }
        addData(root, data);
    }

    void inOrder(nodeptr ptr = NULL){
        if(root == NULL){
            cout << "Empty list\n";
            return;
        }
        if(ptr == NULL){
            ptr = root;
        }
        if(ptr->left)inOrder(ptr->left);
        if(ptr->right)inOrder(ptr->right);
        cout << ptr->data << endl;
    }

} bst;

int32_t main(){
    bst.add(50);
    bst.add(7);
    bst.add(23);
    bst.add(32);
    bst.add(100);
    bst.add(60);

    bst.inOrder();
  
}