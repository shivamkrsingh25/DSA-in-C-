#include <stdio.h>
int Bsearch_Iterative(int A[], int key, int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;

        else if (A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main(void)
{
    int i, n, A[20], key, pos;
    printf("\t\tBinary Search\n");
    printf("\n Enter the size of an array: ");
    scanf("%d", &n);
    printf("\n Enter the elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("\n Enter the element to be searched -> ");
    scanf("%d", &key);
    pos = Bsearch_Iterative(A, key, n);
    if (pos == -1)
    {
        printf("\n Element not found in the given array\n");
    }
    else
    {
        printf("\n Element is found and at index position %d", pos);
    }
    return 0;
}