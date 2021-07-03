#include <bits/stdc++.h>
 
#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
typedef long long ll;
using namespace std;
 
int n,m,t;
const int MAXN = 1e5+10;
vector<int> g[MAXN];
int reach[MAXN], vis[MAXN];
 
bool dfs(int u, int star){
    if(u == t) return true;
    if(vis[u]){
        return 1;
    }
    if(u != star && reach[u]){
        return 0;
    }
    vis[u] = 1;
    int can = 1;
    for(auto v: g[u]){
        if(v!= t && v != star){
            can = can && dfs(v,star);
        }
    }
    if(!can) reach[u]=1;
    return can;
}

 
int main() {FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin>>n>>m>>t;
    vector<int> cand;
    memset(reach,0,sizeof(reach));
    memset(vis,0,sizeof(vis));
    fore(i,0,m){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        if(v == t){
            cand.pb(u);
            reach[u]=1;
        }
    }
    vector<int> ans;
    fore(i,0,SZ(cand)){
        memset(vis,0,sizeof(vis));
        if(dfs(cand[i], cand[i])) 
            ans.pb(cand[i]);
    }
    cout<<SZ(ans)<<"\n";
    sort(ALL(ans));
    fore(i,0,SZ(ans)) cout<<ans[i]<<"\n";
    return 0;
}
 