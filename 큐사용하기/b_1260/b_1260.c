#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode {
    int n;
    struct QueueNode *prev;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *head;
    struct QueueNode *tail;
    int size;
};

void initQueue(struct Queue *queue);
void enqueue(struct Queue *queue, int x);
int dequeue(struct Queue *queue);
int sizeQueue(struct Queue *queue);
int isEmptyQueue(struct Queue *queue);
int frontQueue(struct Queue *queue);
int backQueue(struct Queue *queue);

void DFS(int **a, int DFSvisit[], int v, int n);
void BFS(int **a, int DFSvisit[], int v, int n);

int main() {
    int N, M, V;
    int x, y;
    int **a;
    
   
    int DFSvisit[1001]={0};
    int BFSvisit[1001]={0};

    scanf("%d %d %d", &N, &M, &V);

    a = malloc(sizeof(int *)*(N+1));
    for(int i=0; i<N+1; i++) {
        a[i] = malloc(sizeof(int)*(N+1));
    }

     
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            a[i][j]=0;
        }
    }

    for(int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }

    DFS(a, DFSvisit, V, N);
    printf("\n");
    BFS(a, BFSvisit, V, N);
    
    return 0;
}

void DFS(int **a, int DFSvisit[], int v, int n) {
    DFSvisit[v] = 1;
    printf("%d ", v);
    for(int i=1; i<=n; i++) {
        if(a[v][i]==1 && DFSvisit[i]==0) {
            DFS(a, DFSvisit, i, n);
        }
    }
}

void BFS(int **a, int BFSvisit[], int v, int n) {
    int val;
    struct Queue *queue;
    queue = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(queue);
    enqueue(queue, v);
    BFSvisit[v] = 1;

    while(!isEmptyQueue(queue)) {
        val = dequeue(queue);
        printf("%d ", val);

        for(int i=1; i<=n; i++) {
            if(a[val][i]==1 && BFSvisit[i]==0) {
                enqueue(queue, i);
                BFSvisit[i] = 1;
            }
        }
    }
}

void initQueue(struct Queue *queue) {
    queue->size=0;
    queue->head=NULL;
    queue->tail=NULL;
}

void enqueue(struct Queue *queue, int x) {
    struct QueueNode *node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    
    node->n = x;
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

int sizeQueue(struct Queue *queue) {
    return queue->size;
}

int isEmptyQueue(struct Queue *queue) {
    if(queue->size==0) return 1;
    else return 0;
}

int frontQueue(struct Queue *queue) {
    if(isEmptyQueue(queue)) return -1;
    else return queue->head->n;
}

int backQueue(struct Queue *queue) {
    if(isEmptyQueue(queue)) return -1;
    else return queue->tail->n;
}