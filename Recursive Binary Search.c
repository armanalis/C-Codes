#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node * Rinsert(struct Node *p, int key) {
    struct Node *t;

    if (p==NULL) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key<p->data) {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key>p->data) {
        p->rchild = Rinsert(p->rchild, key);
    }
    return t;

}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int main() {
    struct Node *root = NULL;

    root = Rinsert(root,30);
    root = Rinsert(root,20);
    root = Rinsert(root,25);

    Inorder(root);

    printf("\n");

    return 0;
}
