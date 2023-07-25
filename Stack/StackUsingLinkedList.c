#include <stdio.h>
#include <stdlib.h>
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
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = top;
        top = p;
        return top;
    }
}
int pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = ptr;
        ptr = ptr->next;
        int value = ptr->data;
        free(n);
        return value;
    }
}
int main(int argc, char const *argv[])
{
    int element, value;
    struct Node *top = NULL;
    // top = (struct Node *)malloc(sizeof(struct Node));

    isEmpty(top);
    isFull(top);
    top = push(top, 100);
    top = push(top, 200);
    traverse(top);
    // printf("Pushed %d to the Stack\n", push);
    element = pop(top);
    printf("Poped %d from the Stack\n", element);
    element = pop(top);
    printf("Poped %d from the Stack\n", element);

    return 0;
}
