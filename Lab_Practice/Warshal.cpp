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
    int m;
    cin >> m;
    int v[m + 1][m + 1];
    int w[m + 1][m + 1];
    memset(v, 0, sizeof(v));
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
            if(v[i][j])w[i][j] = v[i][j];
            else w[i][j] = 999999;
        }
    }

    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                v[i][j] |= (v[i][k] & v[k][j]);
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }


    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cout << w[i][j] <<" ";
        }
        cout << '\n';
    }
}