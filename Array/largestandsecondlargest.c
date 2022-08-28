#include <stdio.h>

int main(void)
{
    int n, a[5] = {12, 7, 21, 34, 89};
    int largest = 0, secondlargest = 0;
    printf("Enter ther size of the array: ");
    scanf("%d", &n);
    // printf("\nEnter the elements of the array\n");
    // for(int i = 0;i<n;i++)
    // {
    //     scanf("%d",&a[i]);
    // }
    printf("The elements of the array are as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    largest = a[0];
    secondlargest = a[1];
    if (a[1] > largest)
    {
        secondlargest = largest;
        largest = a[1];
    }
    for (int j = 1; j < n; j++)
    {
        if (a[j + 1] > secondlargest && a[j + 1] > largest)
        {
            secondlargest = largest;
            largest = a[j + 1];
        }
        if (a[j + 1] > secondlargest && a[j + 1] < largest)
        {
            secondlargest = a[j + 1];
        }
    }
    printf("Largest Element: %d, Second largest Element: %d", largest, secondlargest);
}