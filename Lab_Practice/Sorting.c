#include <stdio.h>

void change(int **p) {
    static int y = 50;
    y++;
    *p = &y;
}

int main() {
    int x = 10;
    int *ptr = &x;

    change(&ptr);

    printf("%d\n", *ptr);
    return 0;
}
