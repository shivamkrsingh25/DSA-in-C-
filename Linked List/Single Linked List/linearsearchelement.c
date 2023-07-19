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
struct Node *search(struct Node *head, int element)
{
    struct Node *ptr = head;
    int data, i = 0;
    while (ptr->data !=element)
    {
        ptr = ptr->next;
        i++;
    }
    printf("The element was found at %d\n", i);
}
int main(int argc, char const *argv[])
{
    int data;
    struct Node *head = NULL;
    // head = (struct Node *)malloc(sizeof(struct Node));
    // head = NULL;
    head = insertion(head, 30);
    head = insertion(head, 40);
    head = insertion(head, 20);
    head = insertion(head, 50);
    head = insertion(head, 10);
    traversal(head);
    data = search(head, 30);
    // printf("The element was found at %d", data);
    return 0;
}
