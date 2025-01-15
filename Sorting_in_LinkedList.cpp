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
    int len = 0;
    nodeptr head;
    nodeptr tail;

    LinkedList() : head(nullptr), tail(nullptr){}

    void addFront(T data){len++;
        nodeptr new_node = new Node(data);
        if(!head){
            head = tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void addBack(T data){len++;
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
        nodeptr new_node = new Node(data);
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


template<typename T>
void bubbleSort(LinkedList<T> list){
    for(Node<T>* x = list.head; x; x = x->next){
        for(Node<T>* y = x->next; y; y = y->next){
            if(x->data > y->data){
                swap(x->data, y->data);
            }
        }
    }
}


template<typename T>
LinkedList<T> mergeSort(LinkedList<T> list){
    int n = list.len;
    int mid = n / 2;
    LinkedList<T> left, right;
    Node<T>* temp = list.head;
    for(int i = 0; i < mid; i++){
        left.addBack(temp->data);
        temp = temp->next;
    }
    for(int i = mid; i < n; i++){
        right.addBack(temp->data);
        temp = temp->next;
    }

    if(left.len > 1)left = mergeSort(left);
    if(right.len > 1)right = mergeSort(right);

    list.clearList();
    Node<T>* x = left.head, *y = right.head;
    while(x and y){
        if(x->data < y->data){
            list.addBack(x->data);
            x = x->next;
        }else{
            list.addBack(y->data);
            y = y->next;
        }
    }
    while(x){
        list.addBack(x->data);
        x = x->next;
    }
    while(y){
        list.addBack(y->data);
        y = y->next;
    }
    return list;    
}

int32_t main(){
    int n;
    cin >> n;
    LinkedList<int> list;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.addBack(x);
    }
    list.display();

    list = mergeSort<int>(list);
    list.display();
}