#include <stdio.h>
#include <stdlib.h>

struct  Stack {
    int size;
    int top;
    int *array;
};

void createStack(struct Stack *st) {

    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top=-1;
    st->array = (int *)malloc(st->size * sizeof(int));
    if (st->array == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

}

void displayStack(struct Stack *st) {

    int i;
    for (i=st->top; i>=0; i--) {
        printf("%d ", st->array[i]);
    }
    printf("\n");

}

void push(struct Stack *st, int x) {

    if (st->top == st->size-1)
        printf("Stack overflow\n");
    else {
        st->top++;
        st->array[st->top] = x;
    }

}

int pop(struct Stack *st) {

    int x=-1;
    if (st->top==-1) {
        printf("Stack underflow\n");
    }
    else {
        x=st->array[st->top];
        st->top--;
    }

    return x;
}

int peek(struct Stack *st, int index) {

    int x=-1;
    if (st->top-index+1<0)
        printf("Invalid index\n");
    x =st->array[st->top-index+1];

    return x;
}

int isEmpty(struct Stack *st) {
    if (st->top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack *st) {
    if (st->top==st->size)
        return 1;
    return 0;
}

int stackTop(struct Stack *st) {
    if (!isEmpty(st))
        return st->array[st->top];
    return -1;
}

int main() {

    struct Stack st;
    createStack(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    printf("%d \n", peek(&st,2));

    displayStack(&st);
    free(st.array);

    return 0;
}
