#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    int i = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("\nElement %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct Node *create(struct Node *head)
{
    int data;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    struct Node *ptr;
    ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    // printf("\nEnter the element to be inserted: ");
    // scanf("%d", &data);
    if (head == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = NULL;
        return head;
    }
}
struct Node *insertatHead(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element to be inserted at head: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = ptr;
        head = new;
        return head;
    }
}
struct NOde *insertatEnd(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element to be inserted at end: ");
    scanf("%d", &data);
    new->data = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->next = NULL;
    return head;
}
struct Node *insertatPos(struct Node *head)
{
    int data, pos, i = 0;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the index where the element will be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        while (i != (pos - 1))
        {
            ptr = ptr->next;
            i++;
        }
        new->next = ptr->next;
        ptr->next = new;
        return head;
    }
}
struct Node *insertatVal(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        while (data != ptr->data)
        {
            ptr = ptr->next;
        }
        
    }
}
int main(int argc, char const *argv[])
{
    int data, choice;
    struct Node *head = NULL;
    printf("Enter 1 to create a list\n");
    printf("Enter 2 to display\n");
    printf("Enter 3 to insert at head\n");
    printf("Enter 4 to insert at end\n");
    printf("Enter 5 to insert at any index\n");
    printf("Enter 6 to insert after any val\n");
    printf("Enter 7 to delete at head\n");
    printf("Enter 8 to delete at end\n");
    printf("Enter 9 to delete at any index\n");
    printf("Enter 10 to delete any value\n");
    printf("Enter 11 to count nodes in the list\n");
    printf("Enter 12 to reverse a list\n");
    printf("Enter 13 to exit\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insertatHead(head);
            break;
        case 4:
            head = insertatEnd(head);
            break;
        case 5:
            head = insertatIndex(head);
            break;
        case 6:
            // head = insertatVal(head);
            break;
        case 13:
            exit(1);
        default:
            printf("Oops! Wrong choice\n");
        }
    }

    // struct Node *head = NULL;
    return 0;
}
