#include <stdio.h>
#include <stdint.h>

int main() {
    int x;
    while (1) {
        printf("\n1. Verify");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int n;
            printf("\nEnter 1d array size: ");
            scanf("%d", &n);

            int a[n];
            uintptr_t base = (uintptr_t)a;
            int w = sizeof(int);
            int lb = 0;
            
            for (int i = 0; i < n; i++) {
                uintptr_t loc = base + w * (i - lb);
                uintptr_t add = (uintptr_t)&a[i];

                printf("\nPredicted loc(a[%d]): %zu", i, (size_t)loc);
                printf("\nActual loc(a[%d])   : %zu\n", i, (size_t)add);
            }
        } else if (x == 2) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}