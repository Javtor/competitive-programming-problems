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
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void solve(){
    int n,m;cin>>n>>m;
    vi g[n];
    int raiz = 0;
    vector<int> par(n);
    while(m--){
        int x,y;cin>>x>>y;x--;y--;
        raiz = x;
        g[x].pb(y);g[y].pb(x);
    }
    int qn;cin>>qn;
    vector<ii> q;
    while(qn--){
        int a,b;cin>>a>>b;a--;b--;
        q.pb({a,b});
        par[a]^=1;
        par[b]^=1;
    }
    int cnt = 0;
    for(int i : par) cnt+=i;
    if(cnt){
        cout<<"NO"<<endl<<(cnt/2);
        return;
    }
    cout<<"YES"<<endl;
    vector<vi> t(n);
    vector<bool> vis(n);
    queue<int> qu;
    qu.push(raiz);
    vis[raiz]=1;
    while(SZ(qu)){
        int u = qu.front();qu.pop();
        for(int v : g[u]){
            if(!vis[v]){
                vis[v]=1;
                qu.push(v);
                t[u].pb(v);t[v].pb(u);
            }
        }
    }
    for(auto ab : q){
        int a = ab.fst, b = ab.snd;
        cerr<<a<<' '<<b<<endl;
        vi p(n,-1);
        fore(i,0,n)vis[i]=0;
        while(SZ(qu)){qu.pop();}
        vis[a]=1;
        qu.push(a);
        while(SZ(qu)){
            int u = qu.front();qu.pop();
            bool ya = 0;
            for(int v : t[u]){
                if(!vis[v]){
                    vis[v]=1;
                    qu.push(v);
                    p[v]=u;
                    // if(v==b){ya = 1;break;}
                }
            }
            // if(ya)break;
        }
        vi ans;
        int cur = b;
        while(cur != -1){
            ans.pb(cur);
            cur = p[cur];
        }
        reverse(ALL(ans));
        assert(a==ans[0] && b == ans[SZ(ans)-1]);
        cout<<SZ(ans)<<endl;
        for(int asd : ans)cout<<(asd+1)<<' ';
        cout<<endl;
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
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
