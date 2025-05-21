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

struct Stack{
    const int mx = 50;
    int st[50], id = 0;
    void push(int x){
        if(id >= mx){
            cout << "Overflow\n";
            return;
        }
        st[++id] = x;
    }
    void pop(){
        if(id == 0){
            cout << "Underflow\n";
            return;
        }
        id--;
    }

    int top(){
        if(id == 0){
            cout << "Empty stack\n";
            return 0;
        }
        return st[id];
    }
};

struct Queue{
    const int n = 50;
    int front = 0, rear = 0, q[50];
    void push(int data){
        if((front == 1 and rear == n) or (front == (rear + 1))){
            cout << "Overflow\n";
            return;
        }
        if(front == 0){
            front = 1;
            rear = 1;
        }else if(rear == n){
            rear = 1;
        }else rear++;
        q[rear] = data;
    }

    void pop(){
        if(front == 0){
            cout << "Underflow\n";
            return;
        }
        front++;
        if(front > n)front = 1;
        if(front == rear){
            front = 0;
            rear = 0;
        }
    }

    int beg(){
        if(front == 0){
            cout << "Empty queue\n";
            return;
        }
        return q[front];
    }
};

int32_t main(){
    Stack st;
    st.push(500);
    st.push(50);
    st.push(10);
    st.pop();
    cout << st.top() << endl;
}