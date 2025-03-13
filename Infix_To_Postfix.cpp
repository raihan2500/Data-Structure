#include<bits/stdc++.h>
using namespace std;

int main(){
    string infix = "(A+B)*C-D";
    set<char> oprt = {'+', '-', '*', '/', '%'};

    string postfix;
    stack<char> st, output;

    for(auto c : infix){
        if(c == '('){
            st.push(c);
        }

        if(!oprt.count(c)){
            output.push(c); continue;
        }
    }
}