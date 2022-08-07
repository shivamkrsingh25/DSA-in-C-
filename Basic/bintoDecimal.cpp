#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int num;
    int i = 0, ans = 0, bit = 0;
    cout << "Enter the number: ";
    cin >> num;
    while (num != 0)
    {
        bit = num % 10;
        if (bit == 1)
        {
            ans = ans + pow(2, i);
        }
        num = num / 10;
        i++;
    }
    cout << "Answer is " << ans << endl;
    return 0;
}
