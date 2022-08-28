#include <stdio.h>
int displaybefore(int arr[], int size)
{
    printf("The elements of the array before deletion are as follows:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
int displayafter(int arr[], int size)
{
    printf("The elements of the array before deletion are as follows:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
int deletion(int arr[], int size, int index)
{
    if (index > size)
    {
        printf("The given index cannot be deleted from the array as the index is greater than the size of the array");
    }
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[100], index, size;
    index = 2;
    size = 5;
    for (int i = 0; i < size; i++)
    {
        printf("The element at index %d is:", i);
        scanf("%d", &arr[i]);
    }
    displaybefore(arr, size);
    deletion(arr, size, index);
    size -= 1;
    displayafter(arr, size);
    return 0;
}
