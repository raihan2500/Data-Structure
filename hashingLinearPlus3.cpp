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

void plus3(){
    int n;
    cin >> n;
    vector<int> hs(n);

    auto func = [&](int i){
        return (i + 3) % n;
    };

    for(int i = 0; i < 8; i++){
        int x;
        cin >> x;
        int p = x % n;
        while(hs[p])p = func(p);
        hs[p] = x;        
    }
    print(hs);
}

int32_t main(){
    plus3();  
}