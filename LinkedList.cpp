#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node(T data) : data(data), next(nullptr) {}
    Node* next;
};

template<typename T>
struct LinkedList{
    Node<T>* head;
    LinkedList() : head(nullptr){}

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
        if(!head){head = new_node; return;}
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
    //List of string type
    LinkedList<string> list1;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        list1.addBack(x);
    }
    list1.display();

    //List of int type
    LinkedList<int> list2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list2.addBack(x);
    }
    list2.display();


    //List of vector<int> type
    LinkedList<vector<int>> list3;
    for(int i = 0; i < 3; i++){
        vector<int> temp;
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            temp.push_back(x);
        }
        list3.addBack(temp);
    }

    auto temp = list3.head;
    while(temp != nullptr){
        for(auto i : temp->data)cout << i <<" "; cout << endl;
        temp = temp->next;
    }
}