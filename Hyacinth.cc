#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
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
const int MAXN = 1e4+15;

ll maxfreq;

vi g[MAXN];
vi s[MAXN];

void dfs(int u, int par){
    ll toAs=maxfreq++;
    s[u].pb(toAs);
    bool primer = 1;
    for(auto i : g[u]){
        if(i == par) continue;
        s[i].pb(toAs);
        dfs(i,u);
        if(primer && par==-1){
            primer = 0;
            toAs=maxfreq++;
            s[u].pb(toAs);
        }
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
    maxfreq = 1;

    int n;cin>>n;
    if(n==2){
        cout<<1<<' '<<2<<'\n';
        cout<<2<<' '<<1<<'\n';return 0;
    }
    fore(i,1,n){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    fore(i,0,n){
        cout<<s[i][0]<<' '<<s[i][1]<<'\n';
    }
    return 0;
}
