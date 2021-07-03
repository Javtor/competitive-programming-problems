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
#define MOD 998244353
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

ll fp(ll b, ll e)
{
    ll r = 1;
    while (e)
    {
        if (e & 1LL)
            r = r * b % MOD;
        b = b * b;
        b %= MOD;
        r %= MOD;
        e /= 2;
    }
    return r % MOD;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    fore(n, 1, N+1)
    {
        ll total = 0;
        if (n == N)
        {
            total = 10;
        }
        else
        {
            if (N - n > 0)
            { //Esquinas
                total += 9 * fp(10, N - n - 1) * 2;
                total %= MOD;
            }
            total += 9 * 9 * fp(10, N - n - 2) * (N - (n + 2) + 1);
            total %= MOD;

            total *= 10;
            total %= MOD;
        }
        cout << total << " ";
    }
    return 0;
}
