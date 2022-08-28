#include <stdio.h>
void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);

    // Sorting the ;eft part of the array
    quickSort(arr, s, p - 1);

    // Sorting the right part of the array
    quickSort(arr, p + 1, e);
}
int partition(int arr[], int s, int e)
{
    int pivot, temp;
    int count = 0;
    pivot = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (pivot >= arr[i])
        {
            count++;
        }
    }
    int pivotIndex = s + count;
    temp = arr[s];
    arr[s] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    int i = s, j = e;
    while (i <= pivotIndex && j >= pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] >= arr[pivotIndex])
        {
            j--;
        }
        if (i <= pivotIndex && j >= pivotIndex)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++, j--;
        }
    }
    return pivotIndex;
}
main()
{
    int arr[100], size;
    printf("Enter the elements of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nThe elements of the array are a follows:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, size - 1);
    printf("\nThe elements of the aray after sorting is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}