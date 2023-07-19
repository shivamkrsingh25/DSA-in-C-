#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void traversal(struct Node *ptr)
{
    int i = 0;
    // struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("The list is empty\n");
    }
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
struct Node *insertatBeg(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("Enter the data to be inserted at beginning: ");
    scanf("%d", data);
    printf("\n");
    if (head == NULL)
    {
        new->data = data;
        new->prev = NULL;
        new->prev = NULL;
        return head;
    }
    else
    {
        new->data = data;
        ptr->prev = new;
        new->next = ptr;
        new->prev = NULL;
        return head;
    }
}
struct Node *insertatEnd(struct Node *head)
{
    struct Node *ptr = head;
    int data;
    printf("Enter the data to be inserted at end: ");
    scanf("%d", &data);
    printf("\n");
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
        return new;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->data = data;
        ptr->next = new;
        new->prev = ptr;
        new->next = NULL;
        return head;
    }
}
struct Node *create(struct Node *ptr)
{
    int data;
    printf("Enter the value: ");
    scanf("%d", &data);
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    if (ptr == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        ptr = new;
        return ptr;
    }
    struct Node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new;
    new->prev = p;
    new->next = NULL;
    ptr = p;
    return ptr;
}
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    printf("The list before insertion\n");
    traversal(head);
    head = create(head);
    head = create(head);
    // head = insertatBeg(head);
    head = insertatEnd(head);
    head = insertatEnd(head);
    traversal(head);
    return 0;
}
