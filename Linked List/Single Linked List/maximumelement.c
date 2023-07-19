#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int traverse(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
int maxElement(struct Node *ptr)
{
    int max;
    struct Node *p = ptr;
    max = p->data;
    while (p != NULL)
    {
        if (max <= p->data)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
    // printf("The biggest element is %d", element);
}
int minElement(struct Node *ptr)
{
    int min;
    ;
    struct Node *p = ptr;
    min = p->data;
    while (p != NULL)
    {
        if (min >= p->data)
        {
            min = p->data;
        }
        p = p->next;
    }
    // printf("The smallest element is %d", min);
    return min;
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    //Linking first/head and second node
    head->data = 40;
    head->next = second;

    //Linking second and third node
    second->data = 30;
    second->next = third;

    //Linking third and fourth node
    third->data = 60;
    third->next = fourth;

    //Linking fourth and fifth node
    fourth->data = 20;
    fourth->next = fifth;

    // Terminating the Node
    fifth->data = 100;
    fifth->next = NULL;

    traverse(head);
    int element = maxElement(head);
    int val = minElement(head);
    printf("The biggest element is %d\n", element);
    printf("The smallest element is %d\n", val);
    return 0;
}