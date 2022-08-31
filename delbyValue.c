#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int traversal(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    return i;
}
struct Node *insertion(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return ptr;
}
struct Node *delbyValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = p->next;
    while (p != NULL)
    {
        // if (value == p->data)
        // {
        //     p = p->next;
        //     free(p);
        //     head = q;
        //     return head;
        // }
        if (value == q->data)
        {
            p->next = q->next;
            free(q);
        }
        p->next = q;
        q = q->next;
    }
    head = p;
    return head;
}
int main(int argc, char const *argv[])
{
    int count;
    struct Node *head = NULL;
    // head = (struct Node *)malloc(sizeof(struct Node));
    // head = NULL;
    head = insertion(head, 50);
    head = insertion(head, 40);
    head = insertion(head, 30);
    head = insertion(head, 20);
    head = insertion(head, 10);
    printf("The linked list before deletion is:\n");
    count = traversal(head);
    head = delbyValue(head, 30);
    // binarysearch(head, 30);
    // printf("The total nodes in linked list are %d\n", count);
    printf("The linked list after deletion is:\n");
    traversal(head);
    return 0;
}