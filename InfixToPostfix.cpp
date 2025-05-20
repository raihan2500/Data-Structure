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

int precedence(char c){
    if(c == '^')return 3;
    if(c == '*' or c == '/')return 2;
    if(c == '+' or c == '-')return 1;
    return 0;
}

string infixToPostfix(string infix){
    string postfix;
    stack<char> st;

    for(auto c : infix){
        if(isalnum(c)){
            postfix.push_back(c);
            continue;
        }else if(c == '('){
            st.push(c);
        }else if (c == ')'){
            while(!st.empty() and st.top() != '('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() and precedence(st.top()) >= precedence(c)){
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int32_t main(){
    string infix, postfix;
    cin >> infix;
    
    cout << infixToPostfix(infix) << endl;

  
}