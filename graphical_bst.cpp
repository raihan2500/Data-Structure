#include<bits/stdc++.h>
using namespace std;

#define nl cout << endl;

struct Node{
    int value;
    Node *left, *right;
    Node(int val = 0){
        left = right = nullptr;
        value = val;
    }
};
typedef Node* node;


struct BST{
    node root;
    int mx_size, sz = 1;
    vector<int> temp;
    vector<vector<int>> graph;
    BST(int n = 100){
        mx_size = n;
        root = nullptr;
        temp = vector<int>(200);
        graph.push_back(temp);
    }

    void display(){
        for(auto &v : graph){
            for(auto &i : v){
                if(i == 0)cout << ' ';
                else cout << i <<' ';
            }
            cout << endl;
        }
    }
    void insert(int value, node ptr = nullptr, int i = 0, int j = 32, int inc = 32){
        if(ptr == nullptr)ptr = root;
        if(root == nullptr){
            graph[i][j] = value;
            node new_node = new Node(value);
            root = new_node;
            return;
        }
        inc /= 2;
        if(ptr->value == value)return;
        if(value > ptr->value){
            if(ptr->right != nullptr){
                insert(value, ptr->right, i + 1, j + inc, inc);
            }else{
                node new_node = new Node(value);
                sz++;
                if(sz > mx_size){
                    cout << "Overflow" << endl;
                    return;
                }
                ptr->right = new_node;
                if(graph.size() <= i + 1)graph.push_back(temp);
                graph[i + 1][j + inc] = value;
            }
        }
        if(value < ptr->value){
            if(ptr->left != nullptr){
                insert(value, ptr->left, i + 1, j - inc, inc);
            }else{
                node new_node = new Node(value);
                sz++;
                if(sz > mx_size){
                    cout << "Overflow" << endl;
                    return;
                }
                ptr->left = new_node;
                if(graph.size() <= i + 1)graph.push_back(temp);
                graph[i + 1][j - inc] = value;
            }
        }
    }

    node ptr;
    bool search(int value){
        ptr = root;
        while(ptr != nullptr){
            if(ptr->value == value)return true;
            if(value > ptr->value)ptr = ptr->right;
            else ptr = ptr->left;
        }
        return false;
    }

    void inOrder(node ptr = nullptr, bool start = true){
        if(start){start = false; ptr = root;}
        if(ptr == nullptr)return;

        inOrder(ptr->left, false);
        cout << ptr->value << " ";
        inOrder(ptr->right, false);
    }
};

int32_t main(){
    
    BST bst(32);
    int val = 0;
    while(val >= 0){
        cout << "Enter value: ";
        int val; cin >> val;
        bst.insert(val);

        bst.display();nl;nl;
    }

    bst.inOrder();


}