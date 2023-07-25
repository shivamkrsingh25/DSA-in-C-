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
/*int pop(struct Node *ptr)
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
}*/
int peek(struct Node *ptr, int pos)
{
    struct Node *p = ptr;
    for (int i = 0; i < pos - 1 && pos != NULL; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}
int stackTop(struct Node *ptr)
{
    struct Node *p = ptr;
    if (p != NULL)
    {
        p->data = ptr->data;
        return p->data;
    }
    else
    {
        return -1;
    }
}
int stackBottom(struct Node *ptr)
{
    struct Node *p = ptr;
    for (int i = 0; p != NULL; i++)
    {
        p = p->next;
    }
    return p->data;
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
    // element = pop(top);
    // printf("Poped %d from the Stack\n", element);
    int position = peek(top, 2);
    printf("The data at postion 2 is %d\n", position);
    int stacktop = stackTop(top);
    printf("The element at the top is %d\n", stacktop);
    int stackbottom = stackBottom(top);
    printf("The element at the bottom is %d\n", stackbottom);
    return 0;
}