#include <stdio.h>

void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertsort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i], k = i - 1;

        while (k >= 0 && a[k] > temp) {
            a[k + 1] = a[k];
            k--;
        }

        a[k + 1] = temp;
    }
}

int min(int a[], int k, int n) {
    int m = a[k], loc = k;
    for (int i = k + 1; i < n; i++) {
        if (a[i] < m) {
            m = a[i];
            loc = i;
        }
    }

    return loc;
}

void selectsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int loc = min(a, i, n);

        int temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }
}

void print(int a[], int n) {
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int x;
    while (1) {
        printf("\n1. Bubble sort");
        printf("\n2. Insertion sort");
        printf("\n3. Selection sort");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int n;
            printf("\nEnter array size: ");
            scanf("%d", &n);

            int a[n];
            printf("Enter elements: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            bubblesort(a, n);
            //printf("\nSorted array: ");
            print(a, n);
        } else if (x == 2) {
            int n;
            printf("\nEnter array size: ");
            scanf("%d", &n);

            int a[n];
            printf("Enter elements: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            insertsort(a, n);
            //printf("\nSorted array: ");
            print(a, n);
        } else if (x == 3) {
            int n;
            printf("\nEnter array size: ");
            scanf("%d", &n);

            int a[n];
            printf("Enter elements: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            selectsort(a, n);
            //printf("\nSorted array: ");
            print(a, n);
        } else if (x == 4) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}