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
    Node(T data){
        this->data = data;
        next = prev = nullptr;
    }
};

template<typename T>
struct LinkedList{
    typedef Node<T>* nodeptr;
    int len = 0;
    nodeptr head;
    nodeptr tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void addFront(T data){len++;
        nodeptr new_node = new Node<T>(data);
        if(!head){
            head = tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void addBack(T data){len++;
        nodeptr new_node = new Node<T>(data);
        if(!tail){
            head = tail = new_node;
            return;
        }
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    void deleteFront(){
        if(!head)return;len--;
        if(head->next == nullptr){
            head = tail = nullptr;
            return;
        }
        nodeptr temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
    }

    void deleteBack(){
        if(!tail)return;len--;
        if(tail->prev == nullptr){
            tail = head = nullptr;
            return;
        }
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
        nodeptr new_node = new Node<T>(data);
        for(int i = 1; i < pos and temp; i++){
            temp = temp->next;
        }

        if(!temp){
            cerr << "Out of bound" << endl;
            return;
        }
        if(temp == tail){
            addBack(data);
            return;
        }
        len++;
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
            cerr << "Out of bound" << endl;
            return;
        }
        if(temp == tail){
            deleteBack();
            return;
        }
        len--;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void sortedAdd(T data){

        nodeptr save = nullptr;
        nodeptr temp = head;
        nodeptr newNode = new Node<T>(data);
        if(!head){
            head = tail = newNode;
            return;
        }
        if(data <= head->data){
            addFront(data);
            return;
        }
        if(data >= tail->data){
            addBack(data);
            return;
        }

        while(temp->data < data){
            save = temp;
            temp = temp->next;
        }
        newNode->next = save->next;
        newNode->prev = save;
        save->next = newNode;        
    }

    void display(){
        if(!head){
            cerr << "List is empty!" << endl;
            return;
        }
        nodeptr temp = head;
        while(temp){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clearList(){
        while(head){
            deleteBack();
        }
    }
};

int32_t main(){
    LinkedList<int> list;
    list.sortedAdd(10);
    list.sortedAdd(41);
    list.sortedAdd(3);
    list.sortedAdd(4);
    list.sortedAdd(41);
    list.sortedAdd(50);
    list.display();
    

    LinkedList<string> list1;
    list1.sortedAdd("RU");
    list1.sortedAdd("CSE");

    list1.display();
}