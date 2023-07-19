#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *create(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->prev = new->next = NULL;
        return new;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->next = NULL;
        ptr->next = new;
        new->prev = ptr;
        return head;
    }
}
void display(struct Node *head)
{
    int i = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element %d: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
struct Node *insertatBeg(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element to be inserted at beginning: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->next = new->prev = NULL;
        return new;
    }
    else
    {
        new->prev = NULL;
        new->next = ptr;
        ptr->prev = new;
        head = new;
        return head;
    }
}
struct Node *insertaIndex(struct Node *head)
{
    int data, index, i = 0;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the index: ");
    scanf("%d", &index);
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    new->data = data;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    new->next = ptr->next;
    ptr->next = new;
    new->prev = ptr;
    return head;
}
struct Node *insertafterVal(struct Node *head)
{
    int data, val;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &data);
    printf("\nEnter the element to be inserted after: ");
    scanf("%d", &val);
    new->data = data;
    if (head == NULL)
    {
        new->prev = new->next = NULL;
        return new;
    }
    else
    {
        while (val != ptr->data)
        {
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
        new->prev = ptr;
        return head;
    }
}
struct Node *insertatEnd(struct Node *head)
{
    int data;
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element to be inserted at end: ");
    scanf("%d", &data);
    new->data = data;
    if (head == NULL)
    {
        new->next = new->prev = NULL;
        return new;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->next = NULL;
        ptr->next = new;
        new->prev = ptr;
        return head;
    }
}
struct Node *deleteatBeg(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    else
    {
        head = head->next;
        free(ptr);
        return head;
    }
}
struct Node *deleteatIndex(struct Node *head)
{
    int index, i = 0;
    struct Node *ptr = head;
    struct Node *p;
    p = ptr->next;
    printf("Enter the index to be deleted: ");
    scanf("%d", &index);
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else
    {
        while (i < index - 1)
        {
            ptr = ptr->next;
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        free(p);
        return head;
    }
}
struct Node *deleteVal(struct Node *head)
{
    int val;
    struct Node *ptr = head;
    struct Node *p;
    p = ptr->next;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else
    {
        while (val != p->data)
        {
            ptr = ptr->next;
            p = p->next;
        }
        ptr->next = NULL;
        free(p);
    }
}
struct Node *deleteatEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p;
    p = ptr->next;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            ptr = ptr->next;
            p = p->next;
        }
        free(p);
        ptr->next = NULL;
        return head;
    }
}
int main(int argc, char const *argv[])
{
    int choice;
    struct Node *head = NULL;
    printf("1. To create a list\n");
    printf("2. To dislpay from start to end\n");
    printf("3. To insert at Beginning\n");
    printf("4. To insert after given index\n");
    printf("5. To insert after a given value\n");
    printf("6. To insert at End\n");
    printf("7. To delete at Beginning\n");
    printf("8. To delete at a given index\n");
    printf("9. To delete a given value\n");
    printf("10. To delete at End\n");
    printf("11. To count\n");
    // printf("12. To dislpay from end to start\n");
    printf("13. Exit\n");
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
            head = insertatBeg(head);
            break;
        case 4:
            head = insertaIndex(head);
            break;
        case 5:
            head = insertafterVal(head);
            break;
        case 6:
            head = insertatEnd(head);
            break;
        case 7:
            head = deleteatBeg(head);
            break;
        case 8:
            head = deleteatIndex(head);
            break;
        case 9:
            head = deleteVal(head);
            break;
        case 10:
            head = deleteatEnd(head);
            break;
        case 13:
            exit(1);
        default:
            break;
        }
    }

    return 0;
}