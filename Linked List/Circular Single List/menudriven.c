#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traversal(struct Node *head)
{
    int i = 0;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != head)
        {
            printf("Element %d: %d\n", i, temp->data);
            temp = temp->next;
        }
        printf("Element %d: %d", i, temp->data);
    }
}
struct Node *create(struct Node *head)
{
    int data;
    printf("Enter the value: ");
    scanf("%d", &data);
    printf("\n");
    struct Node *ptr = head;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        new->data = data;
        new->next = new;
        head = new;
        return head;
    }
    else
    {
        new->data = data;
        new->next = ptr->next;
        ptr->next = new;
        head = new;
        return head;
    }
}
struct Node *insertatBeg(struct Node *head)
{
    int data;
    printf("Enter the value to be inserted at the beginning: ");
    scanf("%d", &data);
    printf("\n");
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    new->data = data;
    new->next = head;
    if (head == NULL)
    {
        ptr = ptr->next;
        return ptr;
    }

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    // At this point p points to the last node of this circular linked list

    new->next = head;
    ptr->next = new;
    head = new;
    return head;
}
struct Node *insertatEnd(struct Node *head)
{
    int data;
    printf("Enter the value to be inserted at end: ");
    scanf("%d", &data);
    printf("\n");
    int i = 0;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        new->data = data;
        new->next = new;
        head = new;
        return head;
    }
    // ptr = ptr->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    new->data = data;
    new->next = ptr->next;
    ptr->next = new;
    // head = ptr;
    return head;
}
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    int choice, data, item, pos;
    printf("1.Create List\n");
    printf("2.Display\n");
    printf("3.Count\n");
    printf("4.Search\n");
    printf("5.Add to Empty List / Add at Beginning\n");
    printf("6.Add at End\n");
    printf("7.Add after Node\n");
    printf("8.Add before Node\n");
    printf("9.Add at Position\n");
    printf("10.Delete by Value\n");
    printf("11.Reverse\n");
    printf("12.Quit\n\n");
    while (1)
    {
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            traversal(head);
            break;
        case 3:
            // count(head);
            break;
        case 4:
            printf("Enter the Element to be Searched : ");
            scanf("%d", &data);
            // search(head, data);
            break;
        case 5:
            // printf("Enter the Element to be Inserted : ");
            // scanf("%d", &data);
            head = insertatBeg(head);
            break;
        case 6:
            // printf("Enter the Element to be Inserted : ");
            // scanf("%d", &data);
            head = insertatEnd(head);
            break;
        case 7:
            printf("Enter the Element to be Inserted : ");
            scanf("%d", &data);
            printf("Enter the Element after which to Insert : ");
            scanf("%d", &item);
            // head = addafter(head, data, item);
            break;
        case 8:
            printf("Enter the Element to be Inserted : ");
            scanf("%d", &data);
            printf("Enter the Element before which to Insert : ");
            scanf("%d", &item);
            // head = addbefore(head, data, item);
            break;
        case 9:
            printf("Enter the Element to be Inserted : ");
            scanf("%d", &data);
            printf("Enter the Position at which to Insert : ");
            scanf("%d", &pos);
            // head = addatpos(head, data, pos);
            break;
        case 10:
            printf("Enter the Element to be Deleted : ");
            scanf("%d", &data);
            // head = del(head, data);
            break;
        case 11:
            // head = reverse(head);
            break;
        case 12:
            exit(1);
        default:
            printf("***Wrong Choice***\n");
        } /*End of switch */
    }     /*End of while */
    return 0;
}