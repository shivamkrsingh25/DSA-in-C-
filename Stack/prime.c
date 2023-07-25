#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i = 0, j;
    printf("Enter the range: ");
    scanf("%d ", &j);
    for (i = 0; i < j; i++)
    {
        if (i % 2 != 0)
        {
            printf(" %d", i);
        }
    }

    return 0;
}
