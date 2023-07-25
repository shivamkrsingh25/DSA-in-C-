#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct Stack *s, char a)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = a;
    }
}
char pop(struct Stack *s)
{
    char val;
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int multipleparenthesis(char *exp)
{
    char popped_val;
    int i = 0;
    struct Stack *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_val = pop(sp);
            if (!match(popped_val, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
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
    // struct Stack *s;
    // s->size = 100;
    char *exp = "(100 - {24 + 32(55 + 43)}]";
    if (multipleparenthesis(exp))
    {
        printf("The parenthesis is balanced\n");
    }
    else
    {
        printf("The parenthesis is not balanced\n");
    }
    return 0;
}
