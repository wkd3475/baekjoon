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
void enqueue(struct Queue *queue, int x);
int dequeue(struct Queue *queue);
int size(struct Queue *queue);
int isEmpty(struct Queue *queue);
void turnQueue(struct Queue *queue); //빼지 않고 head, tail만 돌리는 것

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(queue);

    for(int i=0; i<N; i++) {
        enqueue(queue, i+1);
    }
    int check=0;
    while(!isEmpty(queue)) {
        for(int i=0; i<M; i++) {
            if(i<M-1) {
                turnQueue(queue);
            }
            else {
                int v = dequeue(queue);
                if(check==0)
                    printf("<");
                printf("%d", v);
                if(check==N-1) printf(">");
                else printf(", ");

                check++;
            }
        }
    }

    free(queue);
    return 0;
}

void initQueue(struct Queue *queue) {
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void enqueue(struct Queue *queue, int x) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    
    node->n = x;
    node->prev = queue->tail;
    node->next = queue->head;//원형큐 특징
    
    if(isEmpty(queue)) {
        queue->head = node;
    }
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->size++;
}

int dequeue(struct Queue *queue) {
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
        queue->tail->next = queue->head;//원형큐 특징
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

void turnQueue(struct Queue *queue) {
    queue->head = queue->head->next;
    queue->tail = queue->tail->next;
}