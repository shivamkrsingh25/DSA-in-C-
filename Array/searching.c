#include <stdio.h>
int search(int arr[], int element)
{
    for (int i = 0; i < 10; i++)
    {
        if (element == arr[i])
        {
            return i;
        }
        else
            return 0;
    }
}
int main(int argc, char const *argv[])
{
    int array[10], element = 5;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    search(array, element);
    printf("The entered elementy was found at %d", search);
    return 0;
}