#include <iostream>
using namespace std;

int main()
{
    long long int n;
    int m;
    cin >> n >> m;
    long long int llevo = 0;
    long long int ans = 0;
    long long int matches[10];
    for (int i = 0; i < 10; i++)
    {
        matches[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        matches[10 - b] += a;
    }
    for (int i = 0; i < 10; i++)
    {
        if (matches[i] <= n - llevo)
        {
            llevo += matches[i];
            ans += matches[i] * (10 - i);
        }
        else
        {
            ans += (n - llevo) * (10 - i);
            llevo = n;
        }
    }
    cout << ans << endl;
    return 0;
}