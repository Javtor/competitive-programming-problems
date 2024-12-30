#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
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

#define MAXN 2e5+15
typedef long long int ll;

using namespace std;

vector<int> st(MAXN);
vector<vector<int>> g(MAXN);
vector<int> p(MAXN);
vector<ll> d(MAXN,-2e15);

int subtr(int i)
{
    int sz = 0;
    fore(j, 0, SZ(g[i]))
    {
        int val = g[i][j];

        if (val != p[i])
        {
            p[val] = i;
            d[val] = d[i] + 1;
            sz += 1 + subtr(val);
        }
    }
    return st[i] = sz;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;

    p[0] = -1;
    d[0] = 0;
    fore(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    subtr(0);
    fore(i, 0, n)
    {
        d[i] -= st[i];
    }
    sort(ALL(d));
    ll ans = 0;
    fore(i, 0, k)
    {
        ans += d[MAXN - 1 - i];
    }
    cout << ans;

    return 0;
}
