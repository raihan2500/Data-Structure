#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;


int32_t main(){
    int n;
    cin >> n;
    vin arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];

    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if(arr[i] > arr[j])swap(arr[i], arr[j]);
    //     }
    // }

    for(int k = 0; k < n - 1; k++){
        for(int j = 0; j < n - k; j++){
            if(arr[j] > arr[j + 1])swap(arr[j], arr[j + 1]);
        }
    }

    print(arr);
}