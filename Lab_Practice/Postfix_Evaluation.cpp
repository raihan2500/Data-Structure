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

int value[130];

int func(char oprt, int x, int y){
    if(oprt == '+')return x + y;
    if(oprt == '-')return x - y;
    if(oprt == '*')return x * y;
    if(oprt == '/')return x / y;
    if(oprt == '^')return powl(x, y);
    return 0;
}

void postFixEvaluation(string post){
    for(auto &c : post){
        if(isalnum(c))value[c] = 1;
    }
    for(char c = 'a'; c <= 'z'; c++){
        if(value[c]){
            cout << "Enter the value of " << c <<": ";
            cin >> value[c];
        }
    }

    stack<int> st;
    for(auto &c : post){
        if(isalnum(c)){
            st.push(value[c]);
        }else{
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(func(c, x, y));            
        }
    }
    
    cout << st.top() << endl;
}

void preFixEvaluation(){
    string pre;
    cin >> pre;
    reverse(all(pre));
    postFixEvaluation(pre);
}

int32_t main(){
    preFixEvaluation();
}