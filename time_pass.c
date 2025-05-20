#include<stdio.h>

const int N = 2e5;

int ispm[200005];

void seive(){
    // memset(ispm, 0, sizeof(ispm));
    for(int i = 2; i < N; i++){
        if(!ispm[i])
        for(int j = i + i; j < N; j += i){
            ispm[j] = 0;
        }
    }

    for(int i = 2; i < N; i++){
        if(!ispm[i]){
            printf("%d\n", i);
        }
    }
}

__int32_t main(){
    seive();
    
}