#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    struct Node *top;
    int size;
};

struct Node {
    int n;
    struct Node *prev;
};

void push(struct Stack *stack, int x) {
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->n = x;
    node->prev = stack->top;
    stack->top = node;
    stack->size ++;
}

int empty(struct Stack *stack) {
    if(stack->size > 0) return 0;
    else return 1;
}

int pop(struct Stack *stack) {
    if(!empty(stack)) {
        int n = stack->top->n;
        stack->top = stack->top->prev;
        stack->size --;
        return n;
    }
    else return -1;
}

int size(struct Stack *stack) {
    return stack->size;
}

int top(struct Stack *stack) {
    if(empty(stack)) return -1;
    else {
        return stack->top->n;
    }
}

int main() {
    int T;
    char command[6];
    struct Stack *stack;
    stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;

    scanf("%d", &T);

    while(T-->0) {
        scanf("%s", command);

        if(!strcmp("push", command)) {
            int n;
            scanf("%d", &n);

            push(stack, n);
        }
        else if(!strcmp("pop", command)) {
            printf("%d\n", pop(stack));
        }
        else if(!strcmp("size", command)) {
            printf("%d\n", size(stack));
        }
        else if(!strcmp("empty", command)) {
            printf("%d\n", empty(stack));
        }
        else if(!strcmp("top", command)) {
            printf("%d\n", top(stack));
        }
        else
            printf("no!\n");
    }
    return 0;
}