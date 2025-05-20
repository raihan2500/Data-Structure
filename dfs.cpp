#include<bits/stdc++.h>
using namespace std;

int vis[10000];
vector<int> graph[10001];

void dfs(int u = 1){
    vis[u] = 1;
    for(auto child : graph[u]){
        if(vis[child] == 0)dfs(child);
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << endl;
        for(int v : graph[u]){
            if(vis[v] == 0){
                vis[v] = 1;
                q.push(v);
            }
        }
    }


  
}