#include <stdio.h>

int main()
{
    int arr[20][20], i, j, r, c, count = 0;
    printf("Enter The Rows & Columns : ");
    scanf("%d %d", &r, &c);

    printf("\nEnter the Elements of the Matrix : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter the [%d][%d]th element::", i, j);
            scanf("%d", &arr[i][j]);
        }
    } 

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == 0)
                count++;
        }
    }

    printf("\nThe Matrix is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    if (count < ((r * c) / 2))
        printf("\nThis is not a Sparse Matrix");

    else
    {
        printf("\nThe Transpose of the Sparse Matrix is::\n");
        for (j = 0; j < c; j++)
        {
            for (i = 0; i < r; i++)
                printf("%d ", arr[i][j]);

            printf("\n");
        }
    }

    return 0;
}
