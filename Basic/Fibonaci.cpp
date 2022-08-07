#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int num, fib = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    int a = 0, b = 1, c = 0;
    while (fib <= num)
    {
        if (num == 0)
        {
            cout << num << " it is not a fibonaci number" << endl;
        }
        
        fib = a + b;
        a = b;
        b = fib;
        if (fib < num)
        {
            continue;
        }
        else if (fib == num)
        {
            cout << num << " is a fibonaaci number" << endl;
        }
    }
    return 0;
}
