#include <stdio.h>

void push(int a[], int max, int* top, int item) {
    if (*top == max - 1) {
        printf("\nOverflow\n");
        return;
    }

    (*top)++;
    a[*top] = item;
}

void pop(int a[], int* top) {
    if (*top == -1) {
        printf("\nUnderflow\n");
        return;
    }

    (*top)--;
}

void print(int a[], int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[5];
    int max = 5, top = -1;

    int x;
    while (1) {
        printf("\nMax size: 5");
        printf("\nStack: ");
        print(a, top);

        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int item;
            printf("\nEnter item to push: ");
            scanf("%d", &item);

            push(a, max, &top, item);
        } else if (x == 2) {
            pop(a, &top);
        } else if (x == 3) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }
    
    return 0;
}