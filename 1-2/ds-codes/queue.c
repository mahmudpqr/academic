#include <stdio.h>

void insert(int a[], int n, int* front, int* rear, int item) {
    if ((*front == 0 && *rear == n - 1) || *front == *rear + 1) {
        printf("\nOverflow\n");
        return;
    }

    if (*rear == -1) {
        *front = *rear = 0;
    } else if (*rear == n - 1) {
        *rear = 0;
    } else {
        (*rear)++;
    }
    
    a[*rear] = item;
}

void delete(int a[], int n, int* front, int* rear) {
    if (*front == -1) {
        printf("\nUnderflow\n");
        return;
    }

    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*front == n - 1) {
        *front = 0;
    } else {
        (*front)++;
    }
}

void print(int a[], int n, int front, int rear) {
    if (front == -1) return;

    int k = front;
    while(1) {
        printf("%d ", a[k]);

        if (k == rear) {
            break;
        } else if (k == n - 1) {
            k = 0;
        } else {
            k++;
        }
    }
    
    printf("\n");
}

int main() {
    int a[5], n = 5;
    int front = -1, rear = -1;

    int x;
    while (1) {
        printf("\nMax size: 5");
        printf("\nQueue: ");
        print(a, n, front, rear);

        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int item;
            printf("\nEnter item to insert: ");
            scanf("%d", &item);
            
            insert(a, n, &front, &rear, item);
        } else if (x == 2) {
            delete(a, n, &front, &rear);
        } else if (x == 3) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }
    
    return 0;
}