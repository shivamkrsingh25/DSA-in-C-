#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("Pushed %d to the Stack\n", value);
    }
}
int pop(struct Stack *ptr)
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
// void peek(struct Stack *s, int value)
// {
//     if (isEmpty(s))
//     {
//         printf("Stack Underflow\n");
//         return;
//     }
//     for (int i = 0; i < (s->top - 1); i++)
//     {
//         if (s->arr[i] == value)
//         {
//             printf("Element found at %d\n", i);
//         }
//     }
// }
void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        for (int i = 0; i <= (s->top); i++)
        {
            printf("Element %d: %d\n", i, s->arr[i]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int choice, value, element, position;
    struct Stack *s;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Enter the size of the array: ");
    scanf("%d", &s->size);
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for peek\n");
    printf("4 for display\n");
    // printf("Enter choice: ");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be pushed: ");
            scanf("%d", &value);
            push(s, value);
            break;
        case 2:
            element = pop(s);
            printf("\nThe element poped is %d\n", element);
            break;
        case 3:
            printf("\nEnter the element to be searched: ");
            scanf("%d", &value);
            peek(s, value);
            // printf("\nThe element poped is %d\n", element);
            break;
        case 4:
            printf("The elements of the stack are as follows:\n");
            display(s);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return 0;
}
