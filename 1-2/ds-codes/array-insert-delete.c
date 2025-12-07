#include <stdio.h>

void insert(int a[], int* n, int max, int loc, int item) {
    if (*n == max) {
        printf ("\nOverflow\n");
        return;
    }

    for (int i = *n; i >= loc; i--) {
        a[i + 1] = a[i];
    }

    a[loc] = item;
    (*n)++;
}

void delete(int a[], int* n, int loc) {
    if (*n == 0) {
        printf("\nUnderflow\n");
        return;
    }

    for (int i = loc; i < *n; i++) {
        a[i] = a[i + 1];
    }

    (*n)--;
}

int main() {
    int a[10] = {2, 5, 3, 4, 7};
    int max = 10;
    int n = 5;

    int x;
    while (1) {
        printf("\nMax size: 10");
        printf("\nArray: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }

        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int loc, item;
            printf("\nEnter index and item to insert: ");
            scanf("%d%d", &loc, &item);

            insert(a, &n, max, loc, item);
        } else if (x == 2) {
            int loc;
            printf("\nEnter index to delete: ");
            scanf("%d", &loc);

            delete(a, &n, loc);
        } else if (x == 3) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}