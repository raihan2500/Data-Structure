#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

int32_t main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* temp = new Node(4);
    head = tail = temp;

    temp = new Node(5);
    tail->next = temp;
    tail = temp;

    temp = new Node(6);
    temp->next = head;
    head = temp;

    temp = new Node(5);
    tail->next = temp;
    tail = temp;

    temp = new Node(6);
    temp->next = head;
    head = temp;


    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}