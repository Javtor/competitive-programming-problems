#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, -1);
        vector<int> b(n, -1);
        vector<bool> ex(n + 1, false);
        fore(i, 0, n)
        {
            cin >> a[i];
        }
        b[0] = a[0];
        ex[b[0]] = true;
        fore(i, 1, n)
        {
            if (a[i] != a[i - 1])
            {
                b[i] = a[i];
                ex[b[i]] = true;
            }
        }
        int sigue = 1;
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            if (ex[sigue])
            {
                sigue++;
                i--;
            }
            else if (b[i] != -1)
            {
            }
            else
            {
                if (sigue > a[i])
                {
                    pos = false;
                    break;
                }
                else
                {
                    b[i] = sigue;
                    ex[sigue] = true;
                    sigue++;
                }
            }
        }
        if (pos)
        {

            cout << b[0];
            fore(i, 1, n)
            {
                cout << " " << b[i];
            }
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
