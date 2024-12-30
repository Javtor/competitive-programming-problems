#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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

const int MAXN = 1e5+15;

vector<pair<int,ll> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
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

    int n,m,k;cin>>n>>m>>k;
    vector<pair<ii,ll>> edges;
    vector<ii> train;
    fore(i,0,m){
        ll u,v,x;cin>>u>>v>>x;
        edges.pb({{u,v},x});
        edges.pb({{v,u},x});
        g[u].pb({v,x});
        g[v].pb({u,x});

    }
    fore(i,0,k){
        ll s,y;cin>>s>>y;
        train.pb({s,y});
        edges.pb({{1,s},y});
        edges.pb({{s,1},y});
        g[1].pb({s,y});
        g[s].pb({1,y});
    }
    dijkstra(1);
    vector<set<ii>> g2(n+1);
    vector<ll> in(n+1);
    for(auto e : edges){
        if(dist[e.fst.snd] == e.snd+dist[e.fst.fst]){
            g2[e.fst.fst].insert({e.fst.snd,e.snd});
            in[e.fst.snd]++;
        }
    }
    ll ans = 0;
    for(auto t : train){
        if(g2[1].count(t) == 0){
            ans++;
        } else if(in[t.fst] > 1){
            ans++;
            in[t.fst]--;
        }
    }
    cout<<ans<<endl;
    int asd = 4;
    // cout<<fixed<<setprecision(12)<< lo;
    return 0;
}
