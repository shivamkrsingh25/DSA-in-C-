#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Pushed %d to the stack\n", value);
    }
}
int peek(struct stack *ptr)
{
    int value;
    value = ptr->arr[ptr->top];
    return value;
}
int main(int argc, char const *argv[])
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    push(s, 50);
    peek(s);
    printf(" The element is %d", peek(s));
    return 0;
}
