#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b = 1;
    a = 10;
    if (++a)
    {
        cout << b;
    }
    else
    {
        cout << ++b;
    }
    
    return 0;
}
