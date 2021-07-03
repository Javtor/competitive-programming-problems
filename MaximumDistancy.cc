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
int k;
struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,0){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return si[x]==k;
	}

};
int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n, m;cin>>n>>m>>k;
    UnionFind uf(n);
    vector<tuple<ll,ll,ll>> edges;
    fore(i,0,k){
        int kn;cin>>kn;kn--;
        uf.si[kn]=1;
    }
    fore(i,0,m){
        int u,v,w;cin>>u>>v>>w;u--;v--;
        edges.pb({w,u,v});
    }
    sort(ALL(edges));
    fore(i,0,m){
        int u=get<1>(edges[i]);
        int v=get<2>(edges[i]);
        int w=get<0>(edges[i]);
        if(u != v){
            if(uf.join(u,v)){
                fore(i,0,k)cout<<w<<' ';
                return 0;
            }
        }
    }
    return 0;
}
