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
    node(int data) : data(data){

    };
    node *left, *right;
    bool r_flg = false;
};

struct TBT{
    node *root = nullptr;
    void insert(int data, node* it){
        if(root == nullptr){
            root = new node(data);
            return;
        }
        if(it == nullptr){
            it = root;
        }

        if(it->data < data){
            if(it->left == nullptr)it->left = new node(data);
            else insert(data, it->left);
        }
        else {
            if(it->right == nullptr)it->right = new node(data);
            else insert(data, it->right);
        } 
    }
} tbt;

int32_t main(){
    node *it = nullptr;
    
    tbt.insert(5, it);
    tbt.insert(4, it);
    clog << tbt.root->left->data << endl;
}