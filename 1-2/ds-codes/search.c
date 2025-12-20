#include <stdio.h>

int linsearch(int a[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (a[i] == item) {
            return i;
        }
    }

    return -1;
}

int binsearch(int a[], int n, int item) {
    int beg = 0, end = n - 1;
    
    while (beg <= end) {
        int mid = (beg + end) / 2;

        if (a[mid] < item) {
            beg = mid + 1;
        } else  if (a[mid] > item) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int a[12] = {2, 5, 0, 9, 4, 7, 3, 8, 6, 1, 7, 4};
    int b[12] = {0, 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9};
    int n = 12;

    int x;
    while (1) {
        printf("\na[12]: 2, 5, 0, 9, 4, 7, 3, 8, 6, 1, 7, 4");
        printf("\nb[12]: 0, 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9\n");

        printf("\n1. Linear search on a");
        printf("\n2. Binary search on b");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int item;
            printf("\nEnter search item: ");
            scanf("%d", &item);

            int loc = linsearch(a, n, item);

            if (loc == -1) {
                printf("\nNot found\n");
            } else {
                printf("\nFound at index %d\n", loc);
            }
        } else if (x == 2) {
            int item;
            printf("\nEnter search item: ");
            scanf("%d", &item);

            int loc = binsearch(b, n, item);

            if (loc == -1) {
                printf("\nNot found\n");
            } else {
                printf("\nFound at index %d\n", loc);
            }
        } else if (x == 3) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}