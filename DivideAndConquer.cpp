#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(), s.end()
#define fore(i, x, y) for (ll i = x; i < y; i++)
#define SZ(s) ((int)(x).size())
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
using namespace std;

ll fp(ll b, ll e)
{
    ll r = 1;
    while (e)
    {
        if (e & 1LL)
            r = r * b;
        b = b * b;
        e /= 2;
    }
    return r;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll b, d;
    cin >> b >> d;
    fore(m, 1, 100)
    {
        bool pos = true;
        fore(j, 1, 10)
        {
            fore(i, 0, m)
            {
                ll toSum = fp(b, i);
                ll exp = m*j + i;
                ll div = fp(b, exp) + (j%2==0?-toSum:toSum);
                pos = pos && (div) % d == 0;
            }
        }
        if (pos)
        {
            cout << m << "\n";
            return 0;
        }
    }
    cout << "no";
    return 0;
}