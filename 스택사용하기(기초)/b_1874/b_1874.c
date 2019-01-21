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
    int num[100000];
    int count = 0;
    char s[200000];
    int size = 0;
    
    struct Stack *stack;
    stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = 0;

    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        scanf("%d", &num[i]);
    }
    
    push(stack, ++count);
    s[size++] = '+';
    for(int i=0; i<T; i++) {
        while(1) {
            if(num[i]>top(stack)) {
                push(stack, ++count);
                s[size++] = '+';
            }
            else if(num[i]==top(stack)) {
                pop(stack);
                s[size++] = '-';
                break;
            }
            else {
                printf("NO");
                return 0;
            }
        }
    }

    for(int i=0; i<size; i++) {
        printf("%c\n", s[i]);
    }

    return 0;
}