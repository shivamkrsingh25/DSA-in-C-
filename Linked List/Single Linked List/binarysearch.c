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
struct Node *binarysearch(struct Node *head, int element)
{
    int 1 = 0;
    struct Node *ptr = head;
    struct Node *high;
    struct Node *mid;
    struct Node *low = head;
    int data, i = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    high = ptr;
    while (low != high)
    {
        mid = (low->next + high->next) / 2;
        if (element == low->data)
        {
            printf("The element was found at %d",i);
        }
        if (low->data < element)
        {
            low = mid->next;
        }
        else
        {
            high = mid->next;
        }
        i++;
    }

    printf("The element was found at %d\n", i);
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
    count = traversal(head);
    binarysearch(head, 30);
    printf("The total nodes in linked list are %d", count);
    return 0;
}