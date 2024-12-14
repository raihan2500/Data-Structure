#include<bits/stdc++.h>
using namespace std;

#define print(v) for(auto i : v)cout << i <<" ";cout << endl;
#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void merge(int* arr, int lo, int mid, int hi){
    int n = (mid - lo + 1);
    int m = (hi - mid);

    int i = 0, j = 0, k = lo;
    int left[n], right[m];

    for(int i = 0; i < n; i++)left[i] = arr[i + lo];
    for(int j = 0; j < m; j++)right[j] = arr[j + mid + 1];

    for(; i < n and j < m;){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }

    while(i < n) arr[k++] = left[i++];
    while(j < m) arr[k++] = right[j++];
}

void mergeSort(int* arr, int lo, int hi){
    if(lo >= hi)return;
    
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int32_t main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    print(arr);
}