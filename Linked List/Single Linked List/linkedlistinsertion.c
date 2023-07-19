#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertatHead(struct Node *ptr, int data)
{
    struct Node *p = ptr;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = ptr;
    return p;
}
int traversal(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
struct Node *insertatIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = head;
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    p->data = data;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;
}
struct Node *insertatEnd(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = NULL;
    return head;
}
int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linking head and second Node
    head->data = 10;
    head->next = second;

    //Linking second and third node
    second->data = 20;
    second->next = third;

    //Linking third and fouth node
    third->data = 40;
    third->next = NULL;

    printf("Linked list before insertion\n");
    traversal(head);
    head = insertatHead(head, 100);
    printf("Linked list after insertion at head\n");
    traversal(head);
    head = insertatIndex(head, 3, 30);
    printf("Linked list after insertion at Index\n");
    traversal(head);
    head = insertatEnd(head, 200);
    printf("Linked list after insertion at end\n");
    traversal(head);

    return 0;
}
