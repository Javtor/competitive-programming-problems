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

const int N = 10005;

vector<pair<int,int>> g[N];
ll dist[N];
int n,m;ll x;
ll minPath;

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

int main(){
       FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif   
    cin>>n>>m>>x;
    vector<pair<ii,ll>> edges;
    fore(i,0,m){
        ll a,b,w;cin>>a>>b>>w;
        a--;b--;
        edges.pb({{a,b},w});
        g[a].pb({b,w});
        g[b].pb({a,w});
    }
    
    ll l = 1,r = 1e9+1;
    ll ans = -1;
    dijkstra(0);
    minPath = dist[n-1];
    ll newMax = minPath*(100+x);
    //cout<<minPath<<" ";
    while(l<=r){
        ll mid = (l+r)/2;
        fore(i,0,N)g[i].clear();
        fore(i,0,m){
            ll a,b,w;
            a=edges[i].fst.fst;
            b=edges[i].fst.snd;
            w = edges[i].snd;
            if(w<=mid){
                g[a].pb({b,w});
                g[b].pb({a,w});
            }
        }
        dijkstra(0);
        ll newDist = dist[n-1];
        if(newDist > -1 && newDist*100 <= newMax){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    cout<<ans<<"\n";
    return 0;
}

