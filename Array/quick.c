#include <stdio.h>
void quicksort(int arr[], int start, int end)
{
    int size, partitionIndex;
    if (start >= end) // Base Case
    {
        return;
    }
    partitionIndex = partition(arr, start, end);
    quicksort(arr, start, partitionIndex - 1); // Sort the left part of the array
    quicksort(arr, partitionIndex + 1, end);   // Sort the right part of the array
}
int partition(int arr[], int s, int e)
{
    int pivot;
    pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count; // placing pivot at right position of the array
    // swap(arr[s], arr[pivotIndex]);
    int temp = arr[s];
    arr[s] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    // Sorting the left and the right part of the array
    int i = s, j = e;
    while (i <= pivotIndex && j >= pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i <= pivotIndex && j >= pivotIndex)
        {
            // swap(arr[i], arr[j]);
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = a;
}
int main()
{
    int a[100], size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter element %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sorting is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    quicksort(a, 0, size - 1);
    printf("\nThe array after sorting is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    int median,low = 0, high = size;
    median = (low = high) / 2;
    printf("\nThe median element of the given array is %d", a[median]);
    
    return 0;
}
