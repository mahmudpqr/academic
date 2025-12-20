#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        printf("\n%c --> %c\n", a, c);
        return;
    }

    hanoi(n - 1, a, c, b);
    printf("\n%c --> %c\n", a, c);
    hanoi(n - 1, b, a, c);
}

int main () {
    int x;
    while (1) {
        char a = 'A', b = 'B', c = 'C';

        printf("\n1. Play");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int n;
            printf("\nEnter number of disks: ");
            scanf("%d", &n);

            hanoi(n, a, b, c);
        } else if (x == 2) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}