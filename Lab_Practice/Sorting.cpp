#include<stdio.h>
#include<string.h>

void swap_strings(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int strComparator(char *a, char *b){
    int n = strlen(a);
    int m = strlen(b);
    int mn = n;
    if(m < n)mn = m;

    for(int i = 0; i < mn; i++){
        if(a[i] > b[i])return true;
        else if(a[i] < b[i])false;
    }
    return n > m;
}

void sortingStringArray(){
    int n;
    scanf("%d", &n);
    char *arr[n + 1];
    for(int i = 1; i <= n; i++){
        scanf("%s", arr[i]);
    }

    // for(int i = 1; i <= n - 1; i++){
    //     for(int j = 1; j <= n - i; j++){
    //         if(strComparator(arr[j], arr[j + 1])){
    //             swap_strings(&arr[j], &arr[j + 1]);
    //         }
    //     }
    // }
    for(int i = 1; i <= n; i++){
        printf("%s\n", arr[i]);
        // printf("%d\n", strlen(arr[i]));
    }
}


int main(){
    sortingStringArray();
}