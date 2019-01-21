#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int n;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct _Deque {
    Node *head;
    Node *tail;
    int size;
} Deque;

void init_deque(Deque *deque);
void push_front(Deque *deque, int x);
void push_back(Deque *deque, int x);
int pop_front(Deque *deque);
int pop_back(Deque *deque);
int size(Deque *deque);
int isEmpty(Deque *deque);
int front(Deque *deque);
int back(Deque *deque);

int main() {
    int T;
    char command[20];
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    init_deque(deque);

    scanf("%d", &T);

    while(T-->0) {
        scanf("%s", command);

        if(!strcmp("push_front", command)) {
            int n;
            scanf("%d", &n);

            push_front(deque, n);
        }
        else if(!strcmp("push_back", command)) {
            int n;
            scanf("%d", &n);

            push_back(deque, n);
        }
        else if(!strcmp("pop_front", command)) {
            printf("%d\n", pop_front(deque));
        }
        else if(!strcmp("pop_back", command)) {
            printf("%d\n", pop_back(deque));
        }
        else if(!strcmp("size", command)) {
            printf("%d\n", size(deque));
        }
        else if(!strcmp("empty", command)) {
            printf("%d\n", isEmpty(deque));
        }
        else if(!strcmp("front", command)) {
            printf("%d\n", front(deque));
        }
        else if(!strcmp("back", command)) {
            printf("%d\n", back(deque));
        }
    }

    free(deque);
    return 0;
}

void init_deque(Deque *deque) {
    deque->size=0;
    deque->head=NULL;
    deque->tail=NULL;
}

void push_front(Deque *deque, int x) {
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->n = x;
    node->prev = NULL;

    if(isEmpty(deque)) {
        deque->tail = node;
        node->next = NULL;
    }
    else {
        deque->head->prev = node;
        node->next = deque->head;
    }
    deque->head = node;
    deque->size++;
}

void push_back(Deque *deque, int x) {
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->n = x;
    node->next = NULL;
    
    if(isEmpty(deque)) {
        deque->head = node;
        node->prev = NULL;
    }
    else {
        deque->tail->next = node;
        node->prev = deque->tail;
    }
    deque->tail = node;
    deque->size++;
}

int pop_front(Deque *deque) {
    if(isEmpty(deque)) return -1;
    
    Node *temp = deque->head;
    int val = deque->head->n;

    if(size(deque)==1) {
        deque->tail = NULL;
        deque->head = NULL;
    }
    else {
        deque->head = deque->head->next;
        deque->head->prev = NULL;
    }
    deque->size --;
    free(temp);

    return val;
}

int pop_back(Deque *deque) {
    if(isEmpty(deque)) return -1;

    Node *temp = deque->tail;
    int val = deque->tail->n;

    if(size(deque)==1) {
        deque->tail = NULL;
        deque->head = NULL;
    }
    else {
        deque->tail = deque->tail->prev;
        deque->tail->next = NULL;
    }
    deque->size --;
    free(temp);
    return val;
}

int size(Deque *deque) {
    return deque->size;
}

int isEmpty(Deque *deque) {
    if(size(deque)==0) return 1;
    else return 0;
}

int front(Deque *deque) {
    if(isEmpty(deque)) return -1;
    return deque->head->n;
}

int back(Deque *deque) {
    if(isEmpty(deque)) return -1;
    return deque->tail->n;
}