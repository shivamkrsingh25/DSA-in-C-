#include <iostream>
#include <math.h>
using namespace std;
main()
{
    int num, bit, i = 0;
    int ans = 0;
    cout << "Enter the number: ";
    cin >> num;
    while (num != 0)
    {
        bit = num & 1;
        ans = (!bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << "Answer is " << ans << endl;
    int comp = 0, j = 0;
    while (ans != 0)
    {
        int digit = ans % 10;
        int c = !(digit);
        comp = (c * pow(10, j)) + comp;
        ans = ans / 10;
        j++;
    }
    cout << "Answer is " << comp << endl;
}