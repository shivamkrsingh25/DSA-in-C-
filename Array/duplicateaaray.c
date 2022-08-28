#include <stdio.h>

int Duplicates(int *, int);

int main()
{
    int a[20], i, result, n;

    printf("Enter the no. of elements= ");
    scanf("%d", &n);

    printf("\nEnter Array Elements :\n ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = Duplicates(a, n);

    printf("\nArray After Removing Duplictes : ");
    for (i = 0; i < result; ++i)
        printf("%d ", a[i]);

    return 0;
}

int Duplicates(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n;)
        {
            if (a[j] == a[i])
            {
                for (k = j; k < n; k++)
                    a[k] = a[k + 1];

                n--;
            }
            else

                j++;
        }
    }
    return n;
}
