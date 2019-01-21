#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode {
    int name;//번호
    int p;//우선순위
    struct QueueNode *prev;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *head;
    struct QueueNode *tail;
    int size;
};

void initQueue(struct Queue *queue);
void enqueue(struct Queue *queue, int name, int p);
int dequeue(struct Queue *queue);
int sizeQueue(struct Queue *queue);
int isEmptyQueue(struct Queue *queue);
void sort(int pq[], int n);

int main() {
    int T, N, M;

    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    int pq[105]={0};
    scanf("%d", &T);

    while(T-->0) {
        initQueue(queue);
        int num = 0;
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++) {
            int p;
            scanf("%d", &p);
            enqueue(queue, i, p);
            pq[i] = p;
        }

        sort(pq, N);

        int check = 0;
        while(!isEmptyQueue(queue)) {
            int curName = queue->head->name;
            int curP = queue->head->p;
            dequeue(queue);

            if(pq[check] == curP){
                check++;
                if(curName == M) {
                    printf("%d\n", check);
                    break;
                }
            }
            else {
                enqueue(queue, curName, curP);
            }
        }
    }
    free(queue);
    return 0;
}

void sort(int pq[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(pq[i]<pq[j]) {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

void initQueue(struct Queue *queue) {
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void enqueue(struct Queue *queue, int name, int p) {
    struct QueueNode *node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    
    node->name = name;
    node->p = p;
    node->prev = queue->tail;
    node->next = NULL;
    
    if(isEmptyQueue(queue)) {
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
    if(isEmptyQueue(queue)) return -1;
    else if(sizeQueue(queue)==1) {
        val = queue->head->name;
        queue->head = NULL;
        queue->tail = NULL;
        queue->size --;
    }
    else {
        val = queue->head->name;
        queue->head = queue->head->next;
        queue->size --;
    }

    return val;
}

int sizeQueue(struct Queue *queue) {
    return queue->size;
}

int isEmptyQueue(struct Queue *queue) {
    if(queue->size==0) return 1;
    else return 0;
}