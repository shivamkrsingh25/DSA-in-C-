#include<iostream>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int i = 1;
    int check = 0;
    int power;
    power = pow(2, i);
    while (power < num)
    {
        power = pow(2, i);
        check = num % power;
        i = i + 1;
    }
    if (check == 0)
    {
        cout << "Divisible";
    }
    else
    {
        cout << "Not divisible";
    }
    
    return 0;
}
