#include <stdio.h>

void secondlargest(int a[], int n, int lar)
{
    int lar2 = a[0];
    int i;
    for (i = 0; i < n; ++i)
    {
        if (a[i] > lar2 && a[i] < lar)
            lar2 = a[i];
    }
    printf("SECOND LARGEST=%d", lar2);
}

void secondsmallest(int a[], int n, int small)

{
    int small2 = a[0];
    int i;
    for (i = 0; i < n; ++i)
    {
        if (a[i] < small2 && a[i] > small)
            small2 = a[i];
    }
    printf("\n SECOND SMALLEST=%d", small2);
}
int main()
{
    int a[50], i, n, lar, small;

    printf("Enter Array Size : ");
    scanf("%d", &n);
    printf("Enter Array Elements : \n");
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    lar = small = a[0];

    for (i = 1; i < n; ++i)
    {
        if (a[i] > lar)
            lar = a[i];

        if (a[i] < small)
            small = a[i];
    }

    secondlargest(a, n, lar);
    secondsmallest(a, n, small);
}
