#include <stdio.h>
#include <stdlib.h>

void Insert(int key);
struct Node* Rinsert(struct Node *p, int key);
void Inorder(struct Node *p);
struct Node* Search(int key);
struct Node* Delete(struct Node *p, int key);
int Height(struct Node *p);
struct Node* Inpre(struct Node *p);
struct Node* InSucc(struct Node *p);

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Insert(int key) {
    struct Node *t=root;
    struct Node *r, *p;

    if (root==NULL) {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild =NULL;
        root = p;
        return;
    }
    while (t!=NULL) {
        r=t;
        if (key<t->data) {
            t=t->lchild;
        }
        else if (key>t->data) {
            t=t->rchild;
        }
        else {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key<r->data)
        r->lchild=p;
    else
        r->rchild = p;

}

struct Node *Rinsert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) {
        p->lchild = Rinsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

struct Node * Search(int key) {
    struct Node *t=root;

    while (t!=NULL) {
        if (key==t->data) {
            return t;
        }
        else if (key<t->data) {
            t=t->lchild;
        }
        else {
            t=t->rchild;
        }
    }
    return NULL;
}

struct Node * Delete(struct Node *p, int key) {

    struct Node *q;
    if (p==NULL){
        return NULL;
    }

    if (p->lchild==NULL && p->rchild==NULL) {
        if (p==root) {
            root = NULL;
        }
        free(p);
        return NULL;

    }

    if (key<p->data)
        p->lchild = Delete(p->lchild, key);

    else if (key>p->data)
        p->rchild = Delete(p->rchild, key);

    else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }

        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int Height(struct Node *p) {
    int x, y;
    if (p==NULL) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);

    if (Height(p->lchild) > Height(p->rchild)) {
        x = Height(p->lchild);
        return x+1;
    }
    else {
        y = Height(p->rchild);
        return y+1;
    }
    /*return x > y ? x+1 : y+1; This is the same thing at line 130-136.*/
}

struct Node *Inpre(struct Node *p) {
    while (p && p->rchild!=NULL) {
        p =p->rchild;

    }
    return p;
}

struct Node *InSucc(struct Node *p) {
    while (p && p->rchild!=NULL) {
        p =p->rchild;

    }
    return p;
}

int main() {
    struct Node *temp;

    root = Rinsert(root,50);
    Rinsert(root,10);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,30);

    Delete(root, 50);


    Inorder(root);
    printf("\n");

    temp = Search(20);
    if (temp!=NULL) {
        printf("Element %d is found\n", temp->data);
    }
    else {
        printf("Element is not found\n");
    }
    return 0;
}
