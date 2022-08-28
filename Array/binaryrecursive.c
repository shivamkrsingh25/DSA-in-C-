#include <stdio.h>
int binarysearch(int *arr, int key, int low, int high)
{
    int mid = (low + high) / 2;
    int ans;
    // Base case
    if (low > high)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return mid;
    }

    if (key > arr[mid])
    {
        ans = binarysearch(arr, key, mid + 1, high);
        return ans;
    }
    else
    {
        ans = binarysearch(arr, key, low, mid - 1);
        return ans;
    }
}
int main(int argc, char const *argv[])
{
    int arr[100];
    int size, start = 0;
    int element;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are as follows: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nWhich element do you want to find? ");
     scanf("%d", &element);
    int answer = binarysearch(arr, element, start, size);
    printf("The element was found at %d index\n", answer);
    return 0;
}
