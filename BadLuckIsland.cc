#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a, b) memset(a, b, sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int R, S, P;
    cin >> R >> S >> P;
    vector<vector<vector<double>>> dp(R+1);
    fore(i, 0, R + 1)
    {
        dp[i].resize(S+1);
        fore(j, 0, S + 1)
        {
            dp[i][j].resize(P+1);
        }
    }
    dp[R][S][P] = 1.0;
    for (int r = R; r >= 0; r--)
        for (int s = S; s >= 0; s--)
            for (int p = P; p >= 0; p--)
            {
                if (r + s + p == 0)
                    continue;
                double act = dp[r][s][p];
                ll rs = r * s;
                ll rp = r * p;
                ll sp = s * p;
                ll div = rs + rp + sp;
                if (rs)
                {
                    dp[r][s - 1][p] += act * (double)rs / (double)div;
                }
                if (rp)
                {
                    dp[r - 1][s][p] += act * (double)rp / (double)div;
                }
                if (sp)
                {
                    dp[r][s][p - 1] += act * (double)sp / (double)div;
                }
            }
    double ansr = 0, anss = 0, ansp = 0;
    fore(i, 1, R+1) ansr += dp[i][0][0];
    fore(i, 1, S+1) anss += dp[0][i][0];
    fore(i, 1, P+1) ansp += dp[0][0][i];
    cout << fixed << setprecision(12) << ansr << ' ' << anss << ' ' << ansp;
    return 0;
}
