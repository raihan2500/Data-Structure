#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class LinkedList{
    Node<T>* head = NULL;

public:
    LinkedList(){}    
    void insertFront(T val){
        Node<T>* newNode = new Node<T>();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void deleteFront(){
        if(!head){
            cout << "list is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void display(){
        if(!head){
            cout << "list is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        while(temp){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int32_t main(){
    LinkedList<string> list;
    list.insertFront("Ahmed");
    list.insertFront("Raihan");
    list.insertFront("Hello");
    list.display();
    list.deleteFront();
    list.display();

    LinkedList<double> listd;
    listd.insertFront(1.5);
    listd.insertFront(2.5);
    listd.insertFront(5.5);
    listd.display();
}