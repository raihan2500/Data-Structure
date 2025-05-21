#include<stdio.h>

#define swap(x, y) x^= y; y ^= x; x ^= y;
#define print(arr, n)      for(int i = 1; i <= n; i++)printf("%d ",arr[i]); printf("\n");


void sortingStringArray(){
    int n;
    scanf("%d", &n);
    char arr[n + 1][100];
    for(int i = 1; i <= n; i++){
        scanf("%s", arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n + 1];

    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);

    //Delete 2nd element
    for(int i = 2; i < n; i++){
        arr[i] = arr[i + 1];
    }
    arr[n] = 0;

    print(arr,n);

    //Sorting
    for(int i = 1; i <= n - 1; i++){
        for(int j = 1; j <= n - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    print(arr, n);

    


}