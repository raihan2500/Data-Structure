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

int precedence(char c){
    if(c == '^')return 3;
    if(c == '*' or c == '/')return 2;
    if(c == '+' or c == '-')return 1;
    return 0;
}

string infToPost(string infix){
    infix.push_back(')');
    stack<char> st;
    st.push('(');
    
    string post;
    
    for(auto &c : infix){
        if(isalnum(c)){
            post.push_back(c);
            continue;
        
        }else if(c == '('){
            st.push('(');

        }else if(c == ')'){
            while(!st.empty() and st.top() != '('){
                post.push_back(st.top());
                st.pop();
            }
            st.pop();
        
        }else{
            while(!st.empty() and precedence(st.top()) >= precedence(c)){
                post.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    return post;
}

string infToPre(string infix){
    reverse(all(infix));
    for(auto &c : infix){
        if(c == ')')c = '(';
        else if(c == '(')c = ')';
    }
    string rev_post = infToPost(infix);
    reverse(all(rev_post));
    return rev_post;
}

int32_t main(){
    string str;
    cin >> str;
    cout << infToPost(str) << endl;
    cout << infToPre(str) << endl;
}