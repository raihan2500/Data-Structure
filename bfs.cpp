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

vector<int> graph[N], vis(N), dist(N);
int n,m;

void bfs(int vertex = 1){
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 0;

    while(!q.empty()){
        vertex = q.front();
        q.pop();
        cout << vertex << endl;
        for(auto child : graph[vertex]){
            if(vis[child])continue;
            vis[child] = true;
            q.push(child);
            dist[child] = dist[vertex] + 1;
        }
    }
}

void reset(){
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        vis[i] = 0;
        dist[i] = 0;
    }
}
void sukuna(){
    cin >> n >> m;
    reset();
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    bfs();

}

int32_t main(){
    sukuna();
  
}