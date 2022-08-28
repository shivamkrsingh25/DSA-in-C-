// #include <stdio.h>
#include <stdio.h>
int main()
{
    int arr[20], i, n, smallest;
    printf("Enter the no. of elements=");
    scanf("%d", &n);

    printf("\nEnter Array Elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int small = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
            small = arr[i];
    }
    printf(" The smallest element is=%d", small);
    int big = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > big)
            big = arr[i];
    }

    printf("\n The biggest element is=%d", big);
    return 0;
}
