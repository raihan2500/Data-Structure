#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
    Node(int val = 0){
        value = val;
        left = right = nullptr;
    }
};
typedef Node* node;

struct BST{
    node root = nullptr;
    int st
    vector<int> temp;
    vector<vector<int>> graph;
    BST(){
        temp = vector<int> (1e3);
    }

    void insert(int value, node ptr = nullptr){
        if(ptr == nullptr)ptr = root;
        if(root == nullptr){
            node new_node = new Node(value);
            root = new_node;
            return;
        }

        if(ptr->value == value)return;
        if(value < ptr->value){
            if(ptr->left != nullptr){
                insert(value, ptr->left);
            }else{
                node new_node = new Node(value);
                ptr->left = new_node;
            }
        }

        if(value > ptr->value){
            if(ptr->right != nullptr){
                insert(value, ptr->right);
            }else{
                node new_node = new Node(value);
                ptr->right = new_node;
            }
        }
    }

    void inorder(node ptr = nullptr, bool start = true){
        if(start){start = false; ptr = root;}
        if(ptr == nullptr)return;

        inorder(ptr->left, false);
        cout << ptr->value << endl;
        inorder(ptr->right, false);
    }
};


int32_t main(){
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(12);
    bst.insert(2);
    bst.inorder();
}