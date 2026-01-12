#include <stdio.h>
#define MAX 10 // The max elements of the queue 

// The structure of the queue 
// First in, First out 
typedef struct {
  int data[MAX];
  int front;
  int rear; 
} Queue; 

// Function to initialize the queue
// The front of the queue starts in the 0 index
// The rear of the queue starts as empty 
void queueInit(Queue *queue) {
  queue->front = 0; 
  queue->rear = -1; 
}

// Checks if the queue is empty 
int isEmpty(Queue *queue) {
  return queue->front > queue->rear; 
}

// Checks if the queue is full 
int isFull(Queue *queue) {
  return queue->rear == MAX-1; 
}

// Function to add a data in the rear of the queue 
void enqueue(Queue *queue, int val) {
  if (isFull(queue)) {
    printf("error: the queue is full!");
    return; 
  }
  
  // before rear = -1 
  // after rear = 0 
  queue->data[++queue->rear] = val; 
}

// Function to remove a data in the front of the queue
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("error: the queue is empty!");
    return -1; 
  }
  
  int removed = queue->data[queue->front];
  queue->front++;
  
  // Returns the value that was removed 
  return removed; 
}

// Function to display the data of the queue
void display_queue_data(Queue *queue) {
  for (int i=queue->front; i <= queue->rear; i++) {
    printf("%d\n", queue->data[i]);
  }
}

int main() {
  Queue queue;
  
  queueInit(&queue);
  
  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  dequeue(&queue);
  
  display_queue_data(&queue);
  return 0; 
}