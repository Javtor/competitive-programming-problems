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
    int n, m;
    cin >> n >> m;
    ll mat[n][m];
    char matC[n][m];
    char last = 'a';
    fore(i, 0, n) fore(j, 0, m)
    {
        char c;
        cin >> c;
        if (j == 0)
        {
            mat[i][j] = 1;
            last = c;
        }
        else
        {
            if (c == last)
            {
                mat[i][j] = mat[i][j - 1] + 1;
            }
            else
            {
                last = c;
                mat[i][j] = 1;
            }
        }
        matC[i][j] = c;
    }
    ll l = 0;
    ll r = min(n, m);
    ll ans = 0;
    while (l <= r)
    {
        bool pos = false;
        ll mid = (l + r) / 2;
        fore(j, 0, m)
        {
            ll acum = 0;
            fore(i, 0, n)
            {
                if (mat[i][j] >= mid)
                    acum++;
                else
                    acum = 0;
                if (acum >= mid)
                    pos = true;
            }
        }
        if (pos)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << (ans * ans) << "\n";
    return 0;
}
