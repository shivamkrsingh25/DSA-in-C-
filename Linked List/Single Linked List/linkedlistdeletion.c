#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int traversal(struct Node *head)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        printf("ELement %d:%d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
struct Node *deleteatHead(struct Node *head)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    head = head->next;
    free(p);
    return head;
}
struct Node *deleteatIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deleteatEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (q->next = NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct Node *deleteatGivenNode(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data== value)
    {
        p->next = q->next;
        free(q);
    }
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

    //linking head and second Node
    head->data = 10;
    head->next = second;

    //linking second and third Node
    second->data = 20;
    second->next = third;

    //linking third and fourth Node
    third->data = 30;
    third->next = fourth;

    //Terminating the last Node
    fourth->data = 40;
    fourth->next = NULL;

    traversal(head);
    printf("Linked list before deletion\n");
    // head = deleteatHead(head);
    // printf("Linked list after deletion at Head\n");
    // traversal(head);
    // head = deleteatIndex(head, 1);
    // printf("Linked list after deletion at Index\n");
    // traversal(head);
    // head = deleteatEnd(head);
    // printf("Linked list after deletion of last Node\n");
    // traversal(head);
    head = deleteatGivenNode(head, 40);
    printf("Linked list after deletion of given Node\n");
    traversal(head);
    return 0;
}
