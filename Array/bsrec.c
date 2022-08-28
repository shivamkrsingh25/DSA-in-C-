#include <stdio.h>
int Bsearch_Recursive(int A[], int key, int low, int high)
{
    int mid;
    if (low > high)
    {
        printf("\n Element does not exist in the array.");
    }
    else
    {
        mid = (low + high) / 2;
        if (A[mid] == key) // elemnt found
        {
            printf("\n Element is found and at index position %d ", mid);
        }
        else if (A[mid] > key) // search on left side
        {
            Bsearch_Recursive(A, key, low, mid - 1);
        }
        else
        {
            Bsearch_Recursive(A, key, mid + 1, high); // search on right side
        }
    }
}
int main(void)
{
    int i, n, A[20], key, beg, end;
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
    beg = 0;
    end = n - 1;
    Bsearch_Recursive(A, key, beg, end);
    return 0;
}