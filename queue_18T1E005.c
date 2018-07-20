#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node Node;

struct Node{
  int value;
  Node* next;
};

Node *head = NULL;

int size(Node* head){
  if (head == NULL) {
    return 0;
  }
  int size = 0;
  Node* current = head;
  while (current != NULL) {
    ++size;
    current = current -> next;
  }
  return size;
}

void enqueue(int val) {
  if (val < 0) {
    printf("Enter a positive value!\n");
    return;
  }

  if (size(head) >= MAXQUEUE) {
    printf("Error: Queue overflow!\n");
    return;
  }

  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->value = val;
  new_node->next = NULL;
  if (size(head) == 0) {
    head = new_node;
    return;
  } else {
    Node* current = head;
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    return;
  }

}

int dequeue(void){
  if(size(head) == 0) {
    printf("Error: Queue is empty.\n");
    return -1;
  }
  Node *to_remove = head;
  int val = 0;
  if(size(head) == 1) {
    head = NULL;
  } else {
    head = head->next;
  }
  val = to_remove->value;
  free(to_remove);
  return val;  
}

void print_queue(void){

  printf("+-----------------\n");
  printf("|");
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current -> next;
  }
  printf("\n");

  printf("+-----------------\n");

}
