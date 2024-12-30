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

const ll INF = 1e18;

struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

const int MAXN = 1e5+5;

int cr[MAXN]; // -1 if prime, some not trivial divisor if 
vector<int> primes;
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0){primes.pb(i);for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;}
}
map<ll,ll> fact(int n){  // must call init_cribe before
	map<ll,ll> r;
	for(auto i:primes){
        while(n%i==0){
            n/=i;
            r[i]++;
        }
    }
    if(n>1)r[n]++;
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
    init_sieve();
    int n,m;cin>>n>>m;
    vector<ll> a(n);
    fore(i,0,n)cin>>a[i];
    int SOURCE = 0;
    int SINK = 1;
    int last = 2;
    vector<map<ll,pair<ll,ll>>> fn(n);
    fore(i,0,n){
        auto mp = fact(a[i]);
        map<ll,pair<ll,ll>> act;
        for(auto pp:mp){
            act[pp.fst]={last++,pp.snd};
        }
        fn[i]=act;
    }
    Dinic fl(last);

    fore(i,0,n){
        for(auto pp:fn[i]){
            if(i%2){
                fl.add_edge(SOURCE,pp.snd.fst,pp.snd.snd);
            } else{
                fl.add_edge(pp.snd.fst,SINK,pp.snd.snd);
            }
        }
    }
    fore(i,0,m){
        int x,y;cin>>x>>y;x--;y--;
        if(y%2)swap(x,y);
        for(auto px:fn[x]){
            ll cuanto = 0;
            if(fn[y].count(px.fst)>0)
                cuanto = min(px.snd.snd,fn[y][px.fst].snd);
            if(cuanto){
                fl.add_edge(px.snd.fst,fn[y][px.fst].fst,cuanto);
            }
        }
    }
    int ans = fl.max_flow(SOURCE,SINK);
    cout<<ans;
    return 0;
}
