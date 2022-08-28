#include <stdio.h>
int displaybefore(int arr[], int size)
{
    printf("The given array before insertion is as follows:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
int displayafter(int arr[], int size)
{
    printf("The given array after insertion is as follows:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
int insertion(int arr[], int element, int index, int size, int capacity)
{
    for (int i = size - 1; i >= index; i--)
    {
        if (size >= capacity)
        {
            return -1;
        }
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main(int argc, char const *argv[])
{
    int array[100];
    int element, index, size;
    element = 60, index = 4, size = 5;
    int capacity = 100;
    // scanf("The element to be inserted is:%d\n", element);
    for (int i = 0; i < size; i++)
    {
        printf("The element at index %d is:", i);
        scanf("%d", &array[i]);
    }
    displaybefore(array, size);
    insertion(array, element, index, size, capacity);
    size += 1;
    displayafter(array, size);
    return 0;
}
