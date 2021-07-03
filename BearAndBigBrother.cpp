#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    double ans = log(a/b) / log(2.0/3.0);
    double a1 = a*pow(3, ceil(ans));
    double b1 = b*pow(2, ceil(ans));
    if (a1 != b1)
    {
        cout << ceil(ans);
    }
    else
    {
        cout << ceil(ans) + 1;
    }

    return 0;
}