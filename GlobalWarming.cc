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

const int MAXN = 200+15;
const int K = 22;
ll d[MAXN][MAXN];
ll dp[1<<K];

ll go(const vector<int> &v, int mask){
    if(mask == (1<<(SZ(v)))-1) return 0;
    ll &r = dp[mask];
    if(r !=-1)return r;
    r = 1e18;
    int p1, p2;
    for (p1 = 0; p1 < SZ(v); p1++) if (!(mask & (1 << p1)))
        break;                              
    for (p2 = p1 + 1; p2 < SZ(v); p2++) if (!(mask & (1 << p2)))     
        r = min(r, d[v[p1]][v[p2]] + go(v, mask | (1 << p1) | (1 << p2)));

    return r;  

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
    mset(d,0);
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    fore(i,0,n)g[i].pb(i);
    fore(i,0,m){
        int p,q;ll c;cin>>p>>q>>c;p--;q--;
        d[p][q]=d[q][p]=c;
        g[p].pb(q);
        g[q].pb(p);
    }
    vector<bool> vis(n,false);
    ll ans = 0;
    fore(i,0,n){
        mset(dp,-1);
        if(vis[i]) continue;
        if(SZ(g[i])&1){cout<<"impossible"<<endl;return 0;}
        ans += go(g[i],0);
        fore(j,0,SZ(g[i]))vis[g[i][j]]=1;
    }
    cout<<ans<<endl;

    return 0;
}
