#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int n;
    struct Node *prev;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
    int size;
};

void initQueue(struct Queue *queue);
void push(struct Queue *queue, int x);
int pop(struct Queue *queue);
int size(struct Queue *queue);
int isEmpty(struct Queue *queue);
int front(struct Queue *queue);
int back(struct Queue *queue);

int main() {
    struct Queue *queue;
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(queue);

    int T;
    char string[10];

    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        scanf("%s", string);
        
        if(!strcmp(string, "push")) {
            int x;
            scanf("%d", &x);
            push(queue, x);
        }
        else if(!strcmp(string, "pop")) {
            printf("%d\n", pop(queue));
        }
        else if(!strcmp(string, "size")) {
            printf("%d\n", size(queue));
        }
        else if(!strcmp(string, "empty")) {
            printf("%d\n", isEmpty(queue));
        }
        else if(!strcmp(string, "front")) {
            printf("%d\n", front(queue));
        }
        else if(!strcmp(string, "back")) {
            printf("%d\n", back(queue));
        }
    }
    return 0;
}

void initQueue(struct Queue *queue) {
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void push(struct Queue *queue, int x) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    
    node->n = x;
    node->prev = queue->tail;
    node->next = NULL;
    
    if(isEmpty(queue)) {
        queue->head = node;
    }
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->size++;
}

int pop(struct Queue *queue) {
    int val;
    if(isEmpty(queue)) return -1;
    else if(size(queue)==1) {
        val = queue->head->n;
        queue->head = NULL;
        queue->tail = NULL;
        queue->size --;
    }
    else {
        val = queue->head->n;
        queue->head = queue->head->next;
        queue->size --;
    }

    return val;
}

int size(struct Queue *queue) {
    return queue->size;
}

int isEmpty(struct Queue *queue) {
    if(queue->size==0) return 1;
    else return 0;
}

int front(struct Queue *queue) {
    if(isEmpty(queue)) return -1;
    else return queue->head->n;
}

int back(struct Queue *queue) {
    if(isEmpty(queue)) return -1;
    else return queue->tail->n;
}