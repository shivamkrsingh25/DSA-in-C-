#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 100
struct Node{
  char data;
  struct Node* next;
};
void push(struct Node** head, int k){
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  new->data = k;
  new->next = (*head);
  (*head) = new;
}
void printNode(struct Node* head){
  if (head == NULL){
    printf("Empty stack.\n");
    return;
  }printf("Reversed string is: ");
  while(head != NULL) {
    printf("%c",head->data);
    head = head->next;
  }printf("\n");
}
int main() {
  struct Node* stack = NULL;
  char str[MAX];
  printf("Enter string:");
  gets(str);
  for(int i=0; str[i] != '\0';i++)
      push(&stack,str[i]);
  printNode(stack);
  return 0;
}
