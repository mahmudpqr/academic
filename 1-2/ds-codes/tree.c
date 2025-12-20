#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* create(int d) {
    node* new = (node*)malloc(sizeof(node));

    new->data = d;
    new->left = NULL;
    new->right = NULL;

    return new;
}

node* add(int d) {
    if(d == -1) {
        return NULL;
    }

    node* root = create(d);

    int ld, rd;
    printf("Enter left and right child of %d (-1 to skip): ", d);
    scanf("%d%d", &ld, &rd);

    root->left = add(ld);
    root->right = add(rd);

    return root;
}

void preord(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preord(root->left);
    preord(root->right);
}

void inord(node* root) {
    if (root == NULL) {
        return;
    }

    inord(root->left);
    printf("%d ", root->data);
    inord(root->right);
}

void postord(node* root) {
    if (root == NULL) {
        return;
    }

    postord(root->left);
    postord(root->right);
    printf("%d ", root->data);
}

void destroy(node* root) {
    if (root == NULL) {
        return;
    }
    
    free(root->left);
    free(root->right);
    free(root);
}

int main() {
    node* root = NULL;

    int x;
    while(1) {
        printf("\n1. Create tree");
        printf("\n2. Preorder traversal");
        printf("\n3. Inorder traversal");
        printf("\n4. Postorder traversal");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &x);

        if (x == 1) {
            int rtd;
            printf("\nEnter root (-1 to skip): ");
            scanf("%d", &rtd);

            root = add(rtd);
        } else if (x == 2) {
            printf("\nPreorder: ");
            preord(root);
            printf("\n");
        } else if (x == 3) {
            printf("\nInorder: ");
            inord(root);
            printf("\n");
        } else if (x == 4) {
            printf("\nPostorder: ");
            postord(root);
            printf("\n");
        } else if (x == 5) {
            break;
        } else {
            printf("\nInvalid choice\n");
        }
    }

    free(root);
    return 0;
}