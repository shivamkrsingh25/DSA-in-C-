#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

int isEmpty()
{
    if (head == NULL)
        return 1;

    else
        return 0;
}

int length()
{
    int i = 0;
    struct Node *n = head;

    while (n != NULL)
    {
        n = n->next;
        i++;
    }

    return i;
}

void push(int d)
{
    struct Node *temp;
    struct Node *ptr;

    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = d;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        ptr->next = temp;
    }
}

void addBegin(int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = d;
    new->next = head;
    new->prev = NULL;

    head = new;
}

void addLast(int d)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n = head;

    while (n->next != NULL)
    {
        n = n->next;
    }

    new->data = d;
    new->prev = n;
    n->next = new;
    new->next = NULL;
}

void addBeforeIndex(int d, int index)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    int len = length();

    if (index == 0)
    {
        new->prev = NULL;
        new->data = d;
        new->next = head;
        head = new;
    }
    else if (index == len)
    {

        addLast(d);
    }
    else
    {
        int i = 0;
        struct Node *n = head;
        while (i != index - 1)
        {
            i++;
            n = n->next;
        }

        new->data = d;
        new->next = n->next;
        new->prev = n;
        n->next->prev = new;
        n->next = new;
    }
}

void addAfterIndex(int d, int index)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (index == length() - 1)
    {
        addLast(d);
    }
    else
    {
        int i = 0;
        struct Node *n = head;
        while (i != index)
        {
            i++;
            n = n->next;
        }

        new->data = d;
        new->next = n->next;
        n->next->prev = new;
        new->prev = n;
        n->next = new;
    }
}

void deleteBegin()
{
    struct Node *n = head;
    head = head->next;
    head->prev = NULL;

    free(n);
}

void deleteLast()
{
    struct Node *n = head;

    if (length() == 1)
    {
        head = NULL;
        free(n);
    }
    else
    {

        while (n->next->next != NULL)
        {
            n = n->next;
        }

        struct Node *temp = n->next;
        n->next = NULL;

        free(temp);
    }
}

void deleteBeforeIndex(int index)
{
    struct Node *n = head;

    if (index == 0)
    {
        printf("Nothing befor index 0\n");
    }
    else if (index == 1)
    {
        head = head->next;
        free(n);
    }
    else if (index == length())
    {
        deleteLast();
    }
    else
    {
        int i = 0;
        while (i != index - 2)
        {
            i++;
            n = n->next;
        }

        struct Node *temp = n->next;

        n->next = n->next->next;
        temp->next->prev = n;
        free(temp);
    }
}

void deleteAfterIndex(int index)
{
    struct Node *n = head;

    if (index == 0 && length() == 1)
    {
        head = NULL;
        free(n);
    }
    else
    {
        int i = 0;
        while (i != index)
        {
            i++;
            n = n->next;
        }

        struct Node *temp = n->next;

        if (temp->next != NULL)
        {
            n->next = n->next->next;
            temp->next->prev = n;
            free(temp);
        }
        else
        {
            n->next = n->next->next;
            free(temp);
        }
    }
}

void printList()
{
    printf("------Printing List--------\n");
    if (isEmpty())
        printf("Empty list\n");
    else

    {
        struct Node *n = head;

        while (n != NULL)
        {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("\n--------------------------\n");
    }
}

int check()
{
    int d;
    printf("Enter 0 to stop operating :\nOr 1 to continue :\n");
    scanf("%d", &d);
    return d;
}

void main()
{

    printf("Enter the number of elements you want to enter\n");
    int number;
    scanf("%d", &number);

    printf("Enter %d elements\n", number);

    int d;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &d);
        push(d);
    }

    printf("len =%d\n", length());
    int checker = 1;
    while (checker)
    {
        printList();

        printf("Enter the operation to perform :\n");
        printf("Enter 1 to : Add at begining\n");
        printf("Enter 2 to : Add at last\n");
        printf("Enter 3 to : Add before a given index\n");
        printf("Enter 4 to : Add after a given index\n");
        printf("Enter 5 to : Delete at begining\n");
        printf("Enter 6 to : Delete at Last\n");
        printf("Enter 7 to : Delete before a given index\n");
        printf("Enter 8 to : Delete after a given index\n");
        int operation;
        scanf("%d", &operation);

        while (operation < 1 || operation > 8)
        {
            printf("Invalid operation! Please enter any valid operation \n");
            scanf("%d", &operation);
        }

        int temp, index;

        switch (operation)
        {
        case 1:
            printf("Enter the value to enter\n");
            scanf("%d", &temp);
            addBegin(temp);

            printList();

            checker = check();
            break;

        case 2:
            printf("Enter the value to enter\n");
            scanf("%d", &temp);
            addLast(temp);
            printList();

            checker = check();
            break;
        case 3:
            printf("Enter the value to enter\n");
            scanf("%d", &temp);
            printf("Enter the index\n");
            scanf("%d", &index);

            while (index < 0 || index > length() + 1)
            {
                printf("Enter valid index\n");
                scanf("%d", &index);
            }

            addBeforeIndex(temp, index);
            printList();

            checker = check();
            break;

        case 4:
            printf("Enter the value to enter\n");
            scanf("%d", &temp);
            printf("Enter the index\n");
            scanf("%d", &index);

            while (index < 0 || index > length())
            {
                printf("Enter valid index\n");
                scanf("%d", &index);
            }

            addAfterIndex(temp, index);
            printList();

            checker = check();
            break;

        case 5:

            deleteBegin();
            printList();

            checker = check();
            break;

        case 6:

            deleteLast();
            printList();

            checker = check();
            break;

        case 7:
            printf("Enter the index\n");
            scanf("%d", &index);

            while (index < 0 || index > length())
            {
                printf("Enter valid index\n");
                scanf("%d", &index);
            }

            deleteBeforeIndex(index);
            printList();

            checker = check();
            break;

        case 8:
            printf("Enter the index\n");
            scanf("%d", &index);

            while (index < 0 || index > length() - 2)
            {
                printf("Enter valid index\n");
                scanf("%d", &index);
            }

            deleteAfterIndex(index);
            printList();

            checker = check();
            break;
        }
    }
}
