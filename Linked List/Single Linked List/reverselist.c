#include <stdio.h>
#include <stdlib.h>
struct node {
 int data; 
 struct node *next; 
}*head;
void createList(int n);
void reverseList();
void displayList();
int main()
{
 int n, choice;
 /*
 * Create a singly linked list of n nodes
 */
 printf("Enter the Total Number of Nodes : ");
 scanf("%d", &n);
 createList(n);
 printf("\nData in the list \n");
 displayList();
 /*
 * Reverse the list
 */
 printf("\nPress 1 to REVERSE the Order of Singly Linked List\n");
 scanf("%d", &choice);
 if(choice == 1)
 {
 reverseList();
 }
 printf("\nData in the List\n");
 displayList();
 return 0;
}
/*
* Create a list of n nodes
*/
void createList(int n)
{
 struct node *newNode, *temp;
 int data, i;
 if(n <= 0)
 {
 printf("List Size must be Greater than Zero.\n");
 return;
 }
 head = (struct node *)malloc(sizeof(struct node));
 if(head == NULL)
 {
 printf("Unable to allocate memory.");
 }
 else
 {
 printf("Enter the Data of Node 1 : ");
 scanf("%d", &data);
 head->data = data; 
 head->next = NULL; 
 temp = head;
 /*
 * Create n nodes and adds to linked list
 */
 for(i=2; i<=n; i++)
 {
 newNode = (struct node *)malloc(sizeof(struct node));
 if(newNode == NULL)
 {
 printf("Unable to allocate memory.");
 break;
 }
 else
 {
 printf("Enter the Data of Node %d : ", i);
 scanf("%d", &data);
 newNode->data = data; 
 newNode->next = NULL; 
 temp->next = newNode; 
 temp = temp->next;
 }
 }
 printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
 }
}
void reverseList()
{
 struct node *prevNode, *curNode;
 if(head != NULL)
 {
 prevNode = head;
 curNode = head->next;
 head = head->next;
 prevNode->next = NULL; // Make first node as last node
 while(head != NULL)
 {
 head = head->next;
 curNode->next = prevNode;
 prevNode = curNode;
 curNode = head;
 }
 head = prevNode; // Make last node as head
 printf("SUCCESSFULLY REVERSED LIST\n");
 }
}
void displayList()
{
 struct node *temp;
 if(head == NULL)
 {
 printf("List is Empty.");
 }
 else
 {
 temp = head;
 while(temp != NULL)
 {
 printf("Data = %d\n", temp->data); 
 temp = temp->next; 
 }
 }
}