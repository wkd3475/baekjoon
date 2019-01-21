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

char top(struct Stack *stack) {
    if(empty(stack)) return -1;
    else {
        return stack->top->n;
    }
}

void clear(struct Stack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

int main() {
    int T;
    char string[55];
    int flag=0;
    
    struct Stack *stack;
    stack = malloc(sizeof(struct Stack));

    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        flag = 0;
        clear(stack);
        scanf("%s", string);
        for(int j=0; j<strlen(string); j++) {
            if(string[j]=='(') {
                push(stack, 1);
            }
            else {
                if(top(stack)==1)
                    pop(stack);
                else {
                    printf("NO\n");
                    flag = 1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==0&&empty(stack)) printf("YES\n");
        else if(flag==0&&!empty(stack)) printf("NO\n");
    }
    
    free(stack);
    return 0;
}