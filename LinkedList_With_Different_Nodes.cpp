#include<bits/stdc++.h>
using namespace std;

/*
We can use different types of node in a single linked list using Inheritance.
Inheritance (polymorphism): Define a base class Node, 
and have various derived classes like IntNode, StringNode, etc.
*/

struct node{
    node *next = nullptr;
    virtual void show() = 0;
};

struct intNode : node{
    int val = 0;
    intNode(int x = 0) : val(x){};
    void show() override{
        cout << "int: " << val << endl;
    };
};

struct strNode : node{
    string str;
    strNode(string tem = ""){str = tem;}
    void show() override{
        cout << "str: " << str << endl;
    }
};

struct LList{
    node *root = nullptr;
    void intInsert(int val){
        node *it = root;
    }
};

int32_t main(){
    node *root = new intNode(50);
    root->show();
    root->next = new strNode("hello");
    root->next->show();
    root->next->next = new strNode("world");
    root->next->next->show();
}