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
typedef pair<pair<ll,ll>,int>  pd; 

const int MAXN = 1e3+15;
vector<pair<int,pair<ll,ll>> > g[MAXN];  // u->[(v,cost)]
pair<ll,ll> dist[MAXN]; //(co2, dist)
ll x[MAXN], y[MAXN];
ll C[MAXN];
ll B;
int N;

ll dp[1000+15][100+15];

ll go(int wh, int left){
    if(left<0) 
        return 1e18;
    if(wh == N+1)
        return 0;
    ll &ans = dp[wh][left];
    if(ans != -1)
        return ans;
    ans = 1e18;
    fore(i,0,g[wh].size()){
        int nxt = g[wh][i].fst;
        int cst = g[wh][i].snd.snd;
        ll cur = go(nxt, left-cst);
        if(cur < 1e18) 
            cur += g[wh][i].snd.fst;
        ans = min(ans,cur);
    }
    return ans;
}


ll distance(int a, int b){
    return ceil(sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])));
}

void addEdge(int a, int b, int medio){
    g[a].pb({b,{C[medio]*distance(a,b),distance(a,b)}});
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
    memset(dp,-1,sizeof(dp));
    ll xh, yh;cin>>xh>>yh;
    ll xd, yd;cin>>xd>>yd;
    cin>>B;
    cin>>C[0];
    int T;cin>>T;
    fore(i,1,T+1){
        cin>>C[i];
    }
    cin>>N;
    x[N]=xh;y[N]=yh;x[N+1]=xd;y[N+1]=yd;
    addEdge(N,N+1,0);
    vector<pair<pair<int,int>,int>> edgesToAdd;
    fore(i,0,N){
        cin>>x[i]>>y[i];
        int l;cin>>l;
        addEdge(N,i,0);
        addEdge(i,N+1,0);
        fore(k,0,l){
            int j, m;cin>>j>>m;
            edgesToAdd.pb({{i,j},m});
        }
    }
    fore(k,0,edgesToAdd.size()){
        int i = edgesToAdd[k].first.first;
        int j = edgesToAdd[k].first.snd;
        int m = edgesToAdd[k].snd;
        addEdge(i,j,m);
        addEdge(j,i,m);
    }
    // dijkstra(N);
    ll ans = go(N,B);
    if(ans == 1e18) 
        ans = -1;
    int asd = 3;
    cout<<ans;
    
    return 0;
}
