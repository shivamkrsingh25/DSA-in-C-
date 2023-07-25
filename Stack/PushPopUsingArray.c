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
int push(struct stack *ptr, int value)
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
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int main(int argc, char const *argv[])
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (isEmpty(s))
    {
        printf("Empty: %d\n", isEmpty(s));
    }
    else
    {
        printf("Empty :%d\n", isEmpty(s));
    }
    push(s, 50);
    pop(s);
    printf("Pop %d from the stack\n", pop(s));
     if (isEmpty(s))
    {
        printf("Empty: %d\n", isEmpty(s));
    }
    else
    {
        printf("Full: %d\n", isFull(s));
    }
    return 0;
}