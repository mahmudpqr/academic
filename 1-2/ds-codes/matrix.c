#include <stdio.h>

int main() {
    int x;
    while (1) {
        printf("\n1. Enter matrices");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int m, n, p, q;
            printf("\nEnter 1st matrix dimensions: ");
            scanf("%d%d", &m, &n);
            printf("Enter 2nd matrix dimensions: ");
            scanf("%d%d", &p, &q);

            if (n == p) {
                int a[m][n], b[p][q], c[m][q];

                printf("\nEnter 1st matrix elements\n");
                for (int i = 0; i < m; i++) {
                    printf("Row %d: ", i + 1);
                    for (int j = 0; j < n; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }

                printf("\nEnter 2nd matrix elements\n");
                for (int i = 0; i < p; i++) {
                    printf("Row %d: ", i + 1);
                    for (int j = 0; j < q; j++) {
                        scanf("%d", &b[i][j]);
                    }
                }

                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < q; j++) {
                        c[i][j] = 0;
                    }
                }

                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < q; j++) {
                        for (int k = 0; k < n; k++) {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }

                printf("\nMultiplied matrix:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < q; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("\nInvalid dimensions\n");
            }
        } else if (x == 2) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}