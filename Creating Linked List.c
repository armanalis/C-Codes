#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node * create(int n);
void display(node *head);

int main() {
    int n;

    node *head = NULL;

    printf("\nEnter how many nodes you want:");
    scanf("%d", &n);
    head = create(n);
    display(head);

    return 0;
}

node * create(int n){
    int i=0;
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;

    for(i=0; i<n; i++){
        temp = (struct node *)malloc(sizeof(struct node *));
        printf("Enter the data for node number: ", i+1);
        scanf("%d", &(temp->data));

        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void display(node * head){

    node *p = head;
    while(p != NULL){
        printf("\t%d->", p->data);
        p = p->next;
    }
}
