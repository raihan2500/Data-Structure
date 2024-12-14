#include<stdio.h>

void merge(int* arr, int lo, int mid, int hi){
    int n = (mid - lo + 1);
    int m = (hi - mid);
    int left[n], right[m];
    
    for(int i = 0; i < n; i++)left[i] = arr[i + lo];
    for(int j = 0; j < m; j++)right[j] = arr[j + mid + 1];

    int i = 0, j = 0, k = lo;
    for(; i < n && j < m;){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }
    while(i < n)arr[k++] = left[i++];
    while(j < m)arr[k++] = right[j++];
}

void mergeSort(int* arr, int lo, int hi){
    if(hi <= lo)return;
    int mid = (lo + hi) / 2;
    
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int search(int* arr, int n, int element){
    int lo = 0, hi = n - 1, mid;

    while(hi > lo){
        mid = (hi + lo) / 2;
        if(arr[mid] < element){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }

    if(arr[lo] == element)return lo + 1;
    else return -1;
}


__int32_t main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)printf("%d ", arr[i]);
    printf("\n");

    printf("%d ", search(arr, n, 7));
}
