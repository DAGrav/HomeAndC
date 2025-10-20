#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

void btUpView(tree *root) {
    static int level = 0;
    if(root == NULL) {
        return;
    }
    if(root->left) {
        level--;
        btUpView(root->left);
        level++;
    }
    printf("%d ", root->key);
    if (level > -1 ) {
        tree* current = root->right;
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->right;
        }
    }
}

void freeTree(tree* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    tree *tr = NULL;
    tr = calloc(1,sizeof(tree));
    tr->key = 10;
    tr->left = calloc(1,sizeof(tree));
    tr->left->key = 5;
    tr->right = calloc(1,sizeof(tree));
    tr->right->key = 15;
    tr->left->left = calloc(1,sizeof(tree));
    tr->left->left->key=3;
    tr->left->right = calloc(1,sizeof(tree));
    tr->left->right->key=7;
    tr->right->left = calloc(1,sizeof(tree));
    tr->right->left->key = 13;
    tr->right->right = calloc(1,sizeof(tree));
    tr->right->right->key = 18;
    tr->left->left->left = calloc(1,sizeof(tree));
    tr->left->left->left->key=1;
    tr->left->right->left = calloc(1,sizeof(tree));
    tr->left->right->left->key=6;
    tr->right->left->right = calloc(1,sizeof(tree));
    tr->right->left->right->key=14;
    tr->left->left->left->left = calloc(1,sizeof(tree));
    tr->left->left->left->left->key=0;
    btUpView(tr);
    freeTree(tr);
    return 0;
}
