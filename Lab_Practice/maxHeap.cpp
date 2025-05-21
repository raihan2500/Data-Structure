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

void heapify(int heap[], int k){
    int par = k / 2;
    if(par == 0)return;
    if(heap[k] > heap[par]){
        swap(heap[k], heap[par]);
        heapify(heap, par);
    }
}

void insert(int heap[], int &n, int data){
    heap[++n] = data;
    heapify(heap, n);
}

int32_t main(){
    int n = 0;
    int heap[10]; 
    memset(heap, -1, sizeof(heap));

    insert(heap, n, 10);
    insert(heap, n, 20);
    insert(heap, n, 5);
    insert(heap, n, 16);

    Forn(i,n)cout << heap[i] <<" ";
}