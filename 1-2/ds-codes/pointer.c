#include <stdio.h>

void print(int* beg, int* end) {
    while (beg < end) {
        printf("%d ", *beg);
        beg++;
    }
    printf("\n");
}

int main() {
    int a[12] = {2, 5, 0, 9, 4, 7, 3, 8, 6, 1, 7, 4};
    int* p[4] = {a, &a[2], &a[6], &a[9]};

    int x;
    while (1) {
        printf("\nContents: 2, 5, 0, 9, 4, 7, 3, 8, 6, 1, 7, 4\n");

        printf("\n1. Group 1");
        printf("\n2. Group 2");
        printf("\n3. Group 3");
        printf("\n4. Group 4");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x > 0 && x < 5) {
            int ind = x - 1;
            int* beg = p[ind], *end;

            if (x == 4) {
                end = a + 12;
            } else {
                end = p[ind + 1];
            }

            printf("\nGroup %d: ", x);
            print(beg, end);
        } else if (x == 5) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}