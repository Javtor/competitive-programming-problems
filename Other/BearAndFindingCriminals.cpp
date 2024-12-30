#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a;
    cin >> n >> a;
    a--;

    int criminals[n];

    for (int i = 0; i < n; i++)
    {
        cin >> criminals[i];
    }

    long long int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 && criminals[a + i] == 1)
        {
            ans++;
            
        }

        else if (a - i < 0 && a + i >= n)
        {
            break;
        }

        else if (a - i >= 0 && a + i < n)
        {
            if (criminals[a - i] + criminals[a + i] != 1)
            {
                ans += criminals[a - i] + criminals[a + i];
            }
        }

        else if (a - i < 0)
        {
            ans += criminals[a + i];
        }

        else if (a + i >= n)
        {
            ans += criminals[a - i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
