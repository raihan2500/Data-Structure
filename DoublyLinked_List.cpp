#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


template<typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;
    Node(T data) : data(data), next(nullptr), prev(nullptr){};
};

template<typename T>
struct LinkedList{
    typedef Node<T>* nodeptr;

    nodeptr head;
    nodeptr tail;

    LinkedList() : head(nullptr), tail(nullptr){}

    void addFront(T data){
        nodeptr new_node = new Node(data);
        if(!head){
            head = tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void addBack(T data){
        nodeptr new_node = new Node(data);
        if(!tail){
            head = tail = new_node;
            return;
        }
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    void deleteFront(){
        if(!head)return;
        nodeptr temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
    }

    void deleteBack(){
        if(!tail)return;
        nodeptr temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete temp;
    }


    void addAt(int pos, int data){
        if(pos == 0){
            addFront(data);
            return;
        }
        nodeptr temp = head;
        nodeptr new_node = new Node(data);
        for(int i = 1; i < pos and temp; i++){
            temp = temp->next;
        }

        if(!temp){
            cout << "Out of bound" << endl;
            return;
        }
        if(temp == tail){
            addBack(data);
            return;
        }
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }

    void deleteAt(int pos){
        if(pos == 0){
            deleteFront();
            return;
        }
        nodeptr temp = head;
        for(int i = 0; i < pos and temp; i++){
            temp = temp->next;
        }
        if(!temp){
            cout << "Out of bound" << endl;
            return;
        }
        if(temp == tail){
            deleteBack();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void display(){
        if(!head){
            cout << "List is empty!" << endl;
            return;
        }
        nodeptr temp = head;
        while(temp){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int32_t main(){
    LinkedList<int> list;

    list.display();
    list.deleteBack();
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.addBack(5);
    list.addBack(6);
    list.addBack(7);
    list.display();

    list.deleteFront();
    list.deleteBack();
    list.addAt(4, 40);
    list.display();
    list.deleteAt(5);
    list.display();  
}