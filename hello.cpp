#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr)      for(auto i : arr)cout << i <<" ";cout << endl;

const int M = 1e9 + 7;
const int N = 2e5 + 10;


int32_t main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Before sorting: "; print(arr);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "After sorting: ";  print(arr);

    int q;
    cout << "Search: " << endl;
    while(cin >> q){
        int lo = 0, hi = n, mid;
        while(hi > lo){
            mid = (lo + hi) / 2;
            if(arr[mid] < q){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        if(hi == n)cout <<"Not found" << endl;
        else cout << "Index of " << q << " is: " << lo << endl;        
    }  
}