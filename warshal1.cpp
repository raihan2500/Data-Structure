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


int32_t main(){
    int n;
    cin >> n;
    vector<vin> v(n, vin(n));
    forn(i,n)forn(j,n)cin >> v[i][j];
    vector<vin> ans = v;

    //warshal
    for(int k = 0; k < n ; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] |= v[i][k] & v[k][j];
            }
        }
    }

    clog << db(ans);
}