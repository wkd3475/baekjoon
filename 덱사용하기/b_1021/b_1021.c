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
void turn(Deque *deque);

int main() {
    int N, M, check, sum=0;
    int num[55];
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    init_deque(deque);

    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++) {
        scanf("%d", &num[i]);
    }

    for(int i=0; i<N; i++) {
        push_back(deque, i+1);
    }

    for(int i=0; i<M; i++) {
        int check = 0;
        int s = size(deque);
        while(1) {
            if(num[i]==front(deque)) {
                pop_front(deque);
                break;
            }
            else {
                turn(deque);
                check++;
            }
        }
        if(s/2 < check)
            check = s - check;

        sum += check;
    }

    printf("%d", sum);
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

    int val = deque->head->n;
    Node *temp = deque->head;

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

    int val = deque->tail->n;
    Node *temp = deque->tail;

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

void turn(Deque *deque) {
    int val = pop_front(deque);
    push_back(deque, val);
}