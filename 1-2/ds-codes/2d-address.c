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
            int m,n;
            printf("\nEnter 2d array size: ");
            scanf("%d%d", &m, &n);

            int a[m][n];
            uintptr_t base = (uintptr_t)a;
            int w = sizeof(int);
            int lb = 0;
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    uintptr_t loc = base + w * ((i - lb) * n + (j - lb));
                    uintptr_t add = (uintptr_t)&a[i][j];

                    printf("\nPredicted loc(a[%d][%d]): %zu", i, j, (size_t)loc);
                    printf("\nActual loc(a[%d][%d])   : %zu\n", i, j, (size_t)add);
                }
            }
        } else if (x == 2) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}