#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

template<class T>
void merge(T &arr, int lo, int mid, int hi){
    int n = (mid - lo + 1);
    int m = (hi - mid);
    T left(n), right(m);
    for(int i = 0; i < n; i++)left[i] = arr[i + lo];
    for(int j = 0; j < m; j++)right[j] = arr[j + mid + 1];
    
    int i = 0, j = 0, k = lo;
    while(i < n and j < m){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    while(i < n)arr[k++] = left[i++];
    while(j < m)arr[k++] = right[j++];
}

template<class T>
void mergeSort(T &arr, int lo, int hi){
    if(lo >= hi)return;

    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}


int32_t main(){
    int n;
    cin >> n;
    
    // vector<vector<int>>v(n, vector<int> (2));
    // for(int i = 0; i < n; i++)for(int j = 0; j < 2; j++)cin >> v[i][j];

    
    // vector<int> v(n);
    vector<double> v(n);
    // vector<string> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];


    mergeSort(v, 0, n - 1);
    // for(auto i : v){
    //     for(auto j : i)cout << j <<" ";
    //     cout << endl;
    // }
    for(auto i : v)cout << i <<" ";
}