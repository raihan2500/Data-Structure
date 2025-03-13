#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define nl cout << endl;

int n,m;
vector<int> graph[N], vis(N);

void dfs(int vertex = 1, int par = -1){
    if(vis[vertex])return;
    vis[vertex] = true;
    cout << vertex << " ";

    for(auto child : graph[vertex]){
        if(vis[child])continue;
        dfs(child);
    }
}

void bfs(int v = 1){

    queue<int> q;
    bool vis[N] = {0};
    q.push(1);

    while(!q.empty()){
        v = q.front();
        q.pop();
        cout << v << " ";
        vis[v] = true;

        for(auto child : graph[v]){
            if(vis[child])continue;
            q.push(child);
        }
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << "DFS: ";
    dfs(1);nl;
    cout << "BFS: ";
    bfs(1);nl;
}