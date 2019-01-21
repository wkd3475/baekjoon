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
// val{(()[])()} => val{(())} + val{([])} + val{()}
int main() {
    int result = 0, temp = 1;
    char string[35];
    
    struct Stack *stack;
    stack = malloc(sizeof(struct Stack));

    clear(stack);
    scanf("%s", string);
    for(int j=0; j<strlen(string); j++) { 
        if(string[j]=='(') {
            push(stack, 2); // 2는 (를 의미
            temp *= 2;
        }
        else if(string[j]=='[') {// 3은 [를 의미
            push(stack, 3);
            temp *= 3;
        }
        else if(string[j]==')') {
            if(string[j-1]=='(')
                result += temp;
            else if(top(stack)==3||empty(stack)) {
                printf("0\n");
                return 0;
            }
            pop(stack);
            temp /= 2;
        }
        else if(string[j]==']') {
            if(string[j-1]=='[')
                result += temp;
            else if(top(stack)==2||empty(stack)) {
                printf("0\n");
                return 0;
            }
            pop(stack);
            temp /= 3;
        }
    }

    if(!empty(stack)) {
        printf("0\n");
        return 0;
    }
    else printf("%d\n", result);
    
    free(stack);
    return 0;
}