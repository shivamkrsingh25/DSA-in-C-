#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct Stack *ptr)
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
int isFull(struct Stack *ptr)
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
void push(struct Stack *p, char data)
{
    if (isFull(p))
    {
        printf("Stack Overflow\n");
        // return 0;
    }
    else
    {
        p->top++;
        p->arr[p->top] = data;
        // printf("Pushed %d to the Stack\n", data);
    }
}
char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}
int parenthesis(char *exp)
{
    struct Stack *p;
    p->size = 100;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(p, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(p))
            {
                return 0;
            }
            pop(p);
        }
    }
    if (isEmpty(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int choice;
    char *exp;
    // struct Stack *s;
    // s->size = 100;
    // s->top = -1;
    // char *exp = "((8)(*--$$9))";
    /*if (isEmpty(s))
    {
        printf("The Stack is empty\n");
    }
    else
    {
        printf("The Stack is not empty\n");
    // */
    // push(s, 100);
    // push(s, 200);
    // push(s, 300);
    printf("1. Enter the expression\n");
    printf("2. Exit\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the expression: ");
            scanf("%c", exp);
            if (parenthesis(exp))
            {
                printf("The parenthesis is not matching\n");
            }
            else
            {
                printf("The parenthesis is matching\n");
            }
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }

    return 0;
}