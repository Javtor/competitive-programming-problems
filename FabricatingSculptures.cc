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
#define mod 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

ll dp[5001][5001];
ll auxM[5001][5001];

ll aux(int s, int b);

ll solve(int s, int b)
{
    if (b == 0 || s <= 1)
        return 1;
    if (dp[s][b] != -1)
    {
        return dp[s][b];
    }
    ll ans = 0;

    ans += solve(s - 1, b);
    int min2 = min(s - 1, b);

    ans += aux(min2, b - min2);
    // for (int i = 1; i <= min2; i++)
    // {
    //     ans += solve(i, b - i) % mod;
    //     ans %= mod;
    // }

    if (b >= s)
    {
        ans += solve(s, b - s);
    }

    return dp[s][b] = ans % mod;
}

ll aux(int s, int b)
{
    long ans = 0;
    if (s == 0)
    {
        return 0;
    }
    if (auxM[s][b] != -1)
    {
        return auxM[s][b];
    }
    ans = solve(s, b) + aux(s - 1, b + 1);

    return auxM[s][b] = ans % mod;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int s, b;
    cin >> s >> b;
    b -= s;
    memset(dp, -1, sizeof(dp));
    memset(auxM, -1, sizeof(auxM));

    ll ans = solve(s, b);

    cout << ans;
    return 0;
}
