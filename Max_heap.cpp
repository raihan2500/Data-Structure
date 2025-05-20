#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n = 0;
int heap[N];

void heapify(int k){
    int par = k / 2;
    if(par == 0)return;

    if(heap[k] > heap[par]){
        swap(heap[k], heap[par]);
        heapify(par);
    }
}

void insert(int item){
    heap[++n] = item;
    heapify(n);
}

int32_t main(){
    memset(heap, -1, sizeof(heap));
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        insert(x);
        clog << "root: " <<  heap[1] << endl;
    }

    for(int i = 1; i <= m; i++){
        cout << heap[i] <<" ";
    }cout << endl;
    
    
}