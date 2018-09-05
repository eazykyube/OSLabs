#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

void printList(struct node *n){
  while (n != NULL){
     printf(" %d ", n->data);
     n = n->next;
  }
}

void insert(struct node *n, struct node *head){
  struct node* last = head; 
  struct node* someNode;     
  while (last != NULL){
     someNode = last;
     last = last->next;
  }
  someNode->next = n; 
}

void delete(struct node *head){
  struct node* last = head; 
  struct node* someNode;    
  someNode = last;
  while (last != NULL){
     if(last->next == NULL){
        someNode->next = NULL;
     }
     someNode = last;
     last = last->next;
  }
}

int main(){
  struct node* head = (struct node*)malloc(sizeof(struct node)); 
  struct node* second = (struct node*)malloc(sizeof(struct node));
  struct node* third = (struct node*)malloc(sizeof(struct node));
  
  head->data = 1;
  head->next = second;  
  second->data = 2; 
  second->next = third;  
  third->data = 3;
  third->next = NULL;

  printList(head);
  printf("\n");
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = 4;
  newNode->next = NULL;
  insert(newNode, head);
  printList(head);
  printf("\n");
  delete(head);
  printList(head);
}
