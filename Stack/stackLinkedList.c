#include <stdlib.h>
#include <stdio.h>
struct Stack
{
    int data;
    struct Stack *next;
};
struct Stack *push(struct Stack *s, int data)
{
    struct Stack *new;
    new = (struct Stack *)malloc(sizeof(struct Stack));
    new->data = data;
    new->next = s;
    s = new;
    return s;
}
int pop(struct Stack *s)
{
    int val;
    struct Stack *ptr = s;
    if (s == NULL)
    {
        printf("Stack Undeflow\n");
        return 0;
    }
    else
    {
        val = s->data;
        ptr = ptr->next;
        free(ptr);
        return val;
    }
}
int main(int argc, char const *argv[])
{
    int choice, value, val;
    printf("Enter 1 for push\n");
    printf("Enter 2 for pop\n");
    // printf("Enter 3 for display\n");
    struct Stack *s = NULL;
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            s = push(s, value);
            break;
        case 2:
            val = pop(s);
            printf("\nPoped %d from the Stack\n", val);
            break;
            // case 3:
            // printf("The elements of the Stack are as folows:\n ");
            // // display(s);
            // break;
        default:
            break;
        }
    }
    return 0;
}
