#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

const int MAXN = 2e5+15;

vector<ll> g[MAXN];
ll dp[MAXN][3]; // dp[i][k], nodo i conectado con k hijos

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    mset(dp,0);
    int n;cin>>n;
    fore(i,0,n-1){
        int p;cin>>p;
        g[p-1].pb(i+1);
    }
    for(int i = n-1;i>=0;i--){
        if(sz(g[i])==0){
            dp[i][2]=1;
            continue;
        }
        dp[i][0]=1;
        for(auto h : g[i]){
            ll si = (dp[h][1]+dp[h][2])%MOD;
            ll no = (dp[h][0]+dp[h][2])%MOD;

            dp[i][2] = (((dp[i][2]+dp[i][1])%MOD*si)%MOD+(dp[i][2]*no)%MOD)%MOD;
            dp[i][1] = ((dp[i][0]*si)%MOD+(dp[i][1]*no)%MOD)%MOD;
            dp[i][0] = (dp[i][0]*no)%MOD;
        }
    }
    ll ans = dp[0][0]+dp[0][2];
    cout<<(int)ans;
    return 0;
}
