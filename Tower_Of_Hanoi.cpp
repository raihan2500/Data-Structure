#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int dpcnt = 0;

void recur(int n, char from, char to, char aux){
    if(n == 0)return;
    recur(n - 1, from, aux, to);
    cout << "Move disk: " << n << " From: " << from
        << " to: " << to << endl;
    recur(n - 1, aux, to, from);
}

int32_t main(){
    int n;
    cin >> n;
    recur(n, 'A', 'C', 'B');
}