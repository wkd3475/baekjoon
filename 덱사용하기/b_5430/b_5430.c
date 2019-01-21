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
void reverse(Deque *deque);
void show_deque(Deque *deque);

int main() {
    int T, n, flag=0;
    char x;
    char p[100010];
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    init_deque(deque);

    scanf("%d", &T);

    while(T-->0) {
        scanf("%s", p);
        scanf("%d", &n);
        int sum = 0;
        while(1) {
            x = getchar();
            if(x >= '0' && x <= '9')
                sum = sum * 10 + x - '0';
            else {
                if(sum > 0)
                    push_back(deque, sum);
                sum = 0;
                if(x == ']') break;
            }
        }

        int len = strlen(p);
        flag = 0;
        int rev = 0;
        for(int i=0; i<len; i++) {
            if(p[i]=='R') {
                rev ++;
            }
            else if(p[i]=='D') {
                if(isEmpty(deque)) {
                    flag = 1;
                    break;
                }
                else {
                    if(rev%2==0) pop_front(deque);
                    else if(rev%2==1) pop_back(deque);
                }
            }
        }
        if(rev%2==1) reverse(deque);
        if(flag == 0) show_deque(deque);
        else if(flag == 1) printf("error\n");
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

void reverse(Deque *deque) {
    Deque *temp = (Deque*)malloc(sizeof(Deque));
    init_deque(temp);
    while(!isEmpty(deque)) {
        push_back(temp, pop_back(deque));
    }

    deque->head = temp->head;
    deque->tail = temp->tail;
    deque->size = temp->size;
    free(temp);
}

void show_deque(Deque *deque) {
    printf("[");
    int l = size(deque);

    for(int i=0; i<l; i++) {
        printf("%d", pop_front(deque));
        if(i<l-1) {
            printf(",");
        }
    }
    printf("]\n");
}