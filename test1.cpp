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

int n, m;
vector<vector<int>> graph(N);

void inorder(int root = 1){
    stack<int> s;
    step2:
    while(!graph[root].empty()){
        root = graph[root][0];
        s.push(root);
    }
    s.pop();
    cout << root << endl;
    if(graph[root].size() > 1){
        s.push(graph[root][1]);
        root = graph[root][1];
    }
    if(!s.empty())goto step2;

}

void preorder(int v = 1){
    cout << "Preorder: ";
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        v = s.top();
        s.pop();

        if(graph[v].size() > 1)s.push(graph[v][1]);
        if(graph[v].size() > 0)s.push(graph[v][0]);
        cout << v << " ";
    }
    cout << endl << endl;
}

void sukuna(){
    cin >> n;
    for(int i = 0; i < n -1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    preorder();
    // inorder();    
}

int32_t main(){
    sukuna();
}