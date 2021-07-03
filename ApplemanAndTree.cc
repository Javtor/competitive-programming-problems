#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));
const int MAXN = 1e5+15;

ll dp[MAXN][2]; // Nodo, mis subarboles tienen un nodo negro?
vector<int> bl;
vector<vector<int>> g(MAXN);

void dfs(int i, int p){
    dp[i][bl[i]] = 1;
    for(auto v : g[i]){
        if(v==p) continue;
        dfs(v,i);
        dp[i][1] = (dp[i][0]*dp[v][1])%MOD+(dp[i][1]*(dp[v][1]+dp[v][0])%MOD)%MOD;
        dp[i][1]%=MOD;
        dp[i][0] = (dp[i][0]*(dp[v][0]+dp[v][1])%MOD)%MOD;
        dp[i][0]%=MOD;
    }
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n;cin>>n;
    mset(dp,0);
    fore(i,0,n-1){
        int p;cin>>p;
        g[p].pb(i+1);
        g[i+1].pb(p);
    }
    fore(i,0,n){
        int c;cin>>c;
        bl.pb(c);
    }
    dfs(0,-1);
    cout<<dp[0][1]%MOD;
    return 0;
}
