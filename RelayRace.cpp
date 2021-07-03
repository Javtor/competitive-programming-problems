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
    int N;
    cin >> N;
    ll c[N][N];
    ll dp[N][N][2];
    mset(dp, -1);
    fore(i, 0, N) fore(j, 0, N)
    {
        int a;
        cin >> a;
        c[i][j] = a;
    }
    fore(i,0,N)fore(j,0,N)dp[i][j][(2 * (N - 1))%2]=-1e17;
    dp[N - 1][N - 1][(2 * (N - 1))%2] = c[N - 1][N - 1];
    for (int diag = 2 * (N - 1) - 1; diag >= 0; diag--)
        for (int i1 = N - 1; i1 >= 0; i1--)
            for (int i2 = N - 1; i2 >= 0; i2--)
            {
                int j1 = diag - i1;
                int j2 = diag - i2;
                if(!((j1>=0 && j1<N) && (j2>=0 && j2<N)))
                    continue;
                ll r = -1e18;
                if((diag+1-(i1)>=0 && diag+1-(i1)<N) && (diag+1-(i2)>=0 && diag+1-(i2)<N))
                    r = max(r, dp[i1][i2][(diag + 1)%2]);
                if(i1<N-1&&(diag+1-(i1+1)>=0 && diag+1-(i1+1)<N) && (diag+1-(i2)>=0 && diag+1-(i2)<N))
                    r = max(r, dp[i1 + 1][i2][(diag + 1)%2]);
                if(i2<N-1&&(diag+1-(i1)>=0 && diag+1-(i1)<N) && (diag+1-(i2+1)>=0 && diag+1-(i2+1)<N))
                    r = max(r, dp[i1][i2 + 1][(diag + 1)%2]);
                if(i1<N-1&&i2<N-1&&(diag+1-(i1+1)>=0 && diag+1-(i1+1)<N) && (diag+1-(i2+1)>=0 && diag+1-(i2+1)<N))
                    r = max(r, dp[i1 + 1][i2 + 1][(diag + 1)%2]);
                
                r += c[i1][j1];
                if (i1 != i2)
                    r += c[i2][j2];
                dp[i1][i2][diag%2]=r;
            }

    cout << dp[0][0][0];
    return 0;
}
