#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n = 5;
    int arr[n];
    // printf("The size of the array is:");
    // scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("The element at index %d is:", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("The elements of the array are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    printf("The elements of the array in reverse order are as follows:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf(" %d", arr[i]);
    }
    return 0;
}
