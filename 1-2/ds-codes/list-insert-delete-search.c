#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void create(node** start, int n) {
    node* ptr = *start;
    printf("\nEnter elements: ");

    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);

        node* new = (node*)malloc(sizeof(node));
        new->data = item;
        new->next = NULL;
        
        if (ptr == NULL) {
            *start = new;
        } else {
            ptr->next = new;
        }
        ptr = new;
    }
}

void print(node* start) {
    node* ptr = start;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void destroy(node* start) {
    node* ptr = start;
    while(ptr != NULL) {
        node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

node* search(node* start, int item) {
    node* ptr = start;
    while(ptr != NULL) {
        if (ptr->data == item) {
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

int main() {
    node* start = NULL;

    int x;
    while (1) {
        printf("\nCurrent list: ");
        print(start);

        printf("\n1. Create list");
        printf("\n2. Search");
        printf("\n3. Insert");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int n;
            printf("\nEnter number of elements: ");
            scanf("%d", &n);

            create(&start, n);
        } else if (x == 2) {
            int item;
            printf("\nEnter search item: ");
            scanf("%d", &item);

            node* loc = search(start, item);

            if(loc == NULL) {
                printf("\nNot found\n");
            } else {
                printf("\nFound at: %p\n", loc);
            }
        }
    }
}