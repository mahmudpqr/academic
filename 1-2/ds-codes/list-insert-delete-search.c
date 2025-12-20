#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(int d) {
    node* new = (node*)malloc(sizeof(node));

    new->data = d;
    new->next = NULL;
    return new;
}

node* add(int d) {
    if (d == -1) {
        return NULL;
    }

    node* start = create(d);

    int nd;
    printf("Enter next element (-1 to skip): ");
    scanf("%d", &nd);

    start->next = add(nd);
    return start;
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

int length(node* start) {
    int len = 0;
    node* ptr = start;

    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }

    return len;
}

void insert(node** start, int index, int item) {
    int len = length(*start);
    if (index < 0 || index > len) {
        printf("\nInvalid index\n");
        return;
    }

    node* new = create(item);

    if (index == 0) {
        new->next = *start;
        *start = new;
        return;
    }

    node* locp = *start;
    for (int i = 0; i < index - 1; i++) {
        locp = locp->next;
    }

    new->next = locp->next;
    locp->next = new;
}

void delete(node** start, int index) {
    int len = length(*start);
    if (index < 0 || index >= len) {
        printf("\nInvalid index\n");
        return;
    }

    node* loc;

    if (index == 0) {
        loc = *start;
        *start = loc->next;
        free(loc);

        return;
    }

    node* locp = *start;
    for (int i = 0; i < index - 1; i++) {
        locp = locp->next;
    }

    loc = locp->next;
    locp->next = loc->next;
    free(loc);
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
            int sd;
            printf("\nEnter first element (-1 to skip): ");
            scanf("%d", &sd);

            start = add(sd);
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
        } else if (x == 3) {
            int item, index;
            printf("\nEnter index and item to insert: ");
            scanf("%d%d", &index, &item);

            insert(&start, index, item);
        } else if (x == 4) {
            int index;
            printf("\nEnter index to delete: ");
            scanf("%d", &index);

            delete(&start, index);
        } else if (x == 5) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    destroy(start);
    return 0;
}