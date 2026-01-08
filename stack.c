#include <stdio.h>
#define MAX 10 // The max elements of the stack

// Stack
// Last in, First out 
typedef struct {
  int top; 
  int data[MAX];
} Stack; 

// Function to initialize the stack as empty
int initStack(Stack *s) {
  s->top = -1; 
}

// Bool function to verify if the stack is empty
// Returns a boolean(1 for true and 0 for false)
int isEmpty(Stack *s) {
  return s->top == -1; 
}

// Bool function to verify if the stack is full
// Returns a boolean(1 for true and 0 for false)
int isFull(Stack *s) {
  return s->top == MAX-1; 
}

// Function to add a value to the top of the stack
void push(Stack *s, int val) {
  // Verify if the stack is full before push a value to the top
  if (isFull(s)) {
    printf("\nError: Stackoverflow!");
    return; 
  }

  // Increments the top
  // Example: 
  // Empty Stack, top = -1 
  // ++s->top, top = 1 

  // Insert the val on the top with index 1
  s->data[++s->top] = val; 
}

// Function to returns/get the value of the top 
int peek(Stack *s) {
  if (isEmpty(s)) {
    printf("\nError: the stack is empty!");
    return 0; 
  }

  return s->data[s->top];
}

// Function to remove the value of the top
int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("\nError: the stack is empty!");
    return 0; 
  }

  int popped = s->data[s->top];
  s->top--;
  return popped;
}

// Function to display the values of the stack
void display(Stack *s) {
  if (isEmpty(s)) {
    printf("\nError: The stack is empty!");
    return;
  }

  for (int i=0; i<s->top+1; i++) {
    printf("%d\n", s->data[i]);
  }

  printf("\n");
}

int main() {
  // The index to acess the stack values in the while loop
  int index = 10; 

  Stack stack;
  Stack *s = &stack; 

  // Init the stack(top = -1)(empty)
  initStack(s);

  while(!isFull(s)) {
    // Push the index value to the top of the stack
    push(s, index);
    // Increments 10 to the index value
    index += 10; 
  }

  // Display of the stack
  display(s);
  // Display of the top value
  printf("\nPeek: %d\n", peek(s));
  printf("----------");
  
  // Remove the top element
  printf("\nPopped: %d\n", pop(s));
  // Display of the stack without the previous top value
  display(s);
  // Display of the new top value
  printf("\nPeek: %d\n", peek(s));

  return 0; 
}