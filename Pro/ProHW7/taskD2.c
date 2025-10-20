#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; // ссылка на родителя
} tree;


tree* findBrother(tree *root, int key) {
    if (root == NULL) return 0;
    if (root->left != NULL && root->left->key == key) {
        return root->right;
    }
    if (root->right != NULL && root->right->key == key) {
        return root->left;
    }
    tree* leftResult = findBrother(root->left, key);
    if (leftResult != NULL) return leftResult;
    tree* rightResult = findBrother(root->right, key);
    if (rightResult != NULL) return rightResult;
    return 0;
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
    tr->left->left->left->left->right = calloc(1,sizeof(tree));
    tr->left->left->left->left->right->key=3;

    tree* brother;
    brother = findBrother(tr, 5);
    printf("Brother node 5: %s\n", brother ? (brother->key == 15 ? "15" : "false") : "no");
    freeTree(tr);
    return 0;
}
