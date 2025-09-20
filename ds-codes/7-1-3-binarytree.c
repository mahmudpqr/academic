#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* create(int val){
    if(val==-1) return NULL;

    int l,r;
    printf("Enter left and right children of %d (-1 if none): ",val);
    scanf("%d%d",&l,&r);

    node* nd=malloc(sizeof(node));
    nd->data=val;
    nd->left=create(l);
    nd->right=create(r);

    return nd;
}
void pre(node* root){
    if(root==NULL) return;

    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}
void in(node* root){
    if(root==NULL) return;

    in(root->left);
    printf("%d ",root->data);
    in(root->right);
}
void post(node* root){
    if(root==NULL) return;

    post(root->left);
    post(root->right);
    printf("%d ",root->data);
}
void delete(node* root){
    if(root==NULL) return;

    delete(root->left);
    delete(root->right);
    free(root);
}

int main(){
    printf("\n=== Binary Tree Traversal ===\n");
    node* root=NULL;

    while(1){
        printf("\nChoose action:");
        printf("\n1. Create tree\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Exit\n");
        printf("\nEnter your choice: ");
        
        int x;
        scanf("%d",&x);

        if(x==1){
            int r;
            printf("\nEnter root value (-1 if none): ");
            scanf("%d",&r);

            if(root!=NULL) delete(root);
            root=create(r);
        }
        else if(x==2){
            printf("\nTraversed in preorder: ");
            pre(root);
            printf("\n");
        }
        else if(x==3){
            printf("\nTraversed in inorder: ");
            in(root);
            printf("\n");
        }
        else if(x==4){
            printf("\nTraversed in postorder: ");
            post(root);
            printf("\n");
        }
        else if(x==5){
            delete(root);
            break;
        }
        else{
            printf("\nInvalid choice!\n");
        }
    }
    printf("\n");
    return 0;
}
