#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int traverse(struct Node *ptr)
{
        int i=0;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
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
    head->data = 20;
    head->next = second;

    //Linking second and third node
    second->data = 30;
    second->next = third;

    //Linking third and fourth node
    third->data = 40;
    third->next = fourth;

    //Linking fourth and fifth node
    fourth->data = 50;
    fourth->next = fifth;

    // Terminating the Node
    fifth->data = 60;
    fifth->next = NULL;

    traverse(head);
    return 0;
}
