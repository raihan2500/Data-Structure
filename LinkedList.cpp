#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<typename T>
struct Node{
    T data;
    Node(T data) : data(data), next(nullptr) {}
    Node* next;
};

template<typename T>
struct Linklist{
    Node<T>* head;
    Linklist() : head(nullptr){}

    void addFront(T data){
        Node<T>* new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
    }

    void deleteFront(){
        if(head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }



    void addBack(T data){
        Node<T>* new_node = new Node<T>(data);
        Node<T>* temp = head;
        while(temp->next != nullptr)temp = temp->next;
        temp->next = new_node;
    }

    void deleteBack(){
        if(head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }

        if(!head->next){
            delete head->next;
            head = nullptr; 
            return;
        }

        Node<T>*temp = head;
        while(temp->next->next)temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }


    void addAt(int pos, int data){
        Node<T>* new_node = new Node<T>(data);
        Node<T>* temp = head;
        if(pos == 0){
            addFront(data);
            return;
        }
        for(int cnt = 1; cnt < pos and temp; cnt++){
            temp = temp->next;
        }

        if(!temp){
            cout << "Position out of bound" << endl;
            delete new_node;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deleteAt(int pos){
        Node<T>* temp = head;

        if(pos == 0){
            deleteFront();
            return;
        }

        for(int cnt = 1; cnt < pos && temp->next; cnt++){
            temp = temp->next;
        }
        if(!temp->next){
            cout << "Position out of bound" << endl;
            return;
        }

        Node<T>* toRem = temp->next;
        temp->next = temp->next->next;
        delete toRem;
    }

    void display(){
        Node<T>* temp = head;
        while(temp != nullptr){
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int32_t main(){
    Linklist<int> list;
    list.addFront(5);
    list.addFront(10);

    list.display();

    list.deleteFront();
    list.display();

    list.addBack(6);
    list.addBack(7);
    list.deleteBack();
    list.addBack(8);
    list.addAt(2, 4);
    list.display();

}