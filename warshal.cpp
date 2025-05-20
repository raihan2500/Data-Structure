#include<bits/stdc++.h>
using namespace std;

const int INF = 10000000;

int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    //Matrix Input
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0)graph[i][j] = INF;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    //print
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INF)cout << -1 <<" ";
            else cout << graph[i][j] <<" ";
        }
        cout << endl;
    }


    
  
}