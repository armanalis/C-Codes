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

int main() {

    struct Stack st;
    createStack(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    displayStack(&st);

    free(st.array);

    return 0;
}
