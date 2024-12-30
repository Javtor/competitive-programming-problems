#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

#define MAXN 1e5+5
typedef long long int ll;

using namespace std;

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, ll s, ll e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return -1e18; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main()
{
    FIN;

    int n;cin>>n;
    vector<pair<ll,ll>> rectangles;

    set<ll> puntos;
    map<ll,ll> trad;

    fore(i,0,n){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        rectangles.pb({y1,y2});
        puntos.insert(-y2);
        puntos.insert(-y1);
    }
    int next = 0;
    for(auto i : puntos){
        trad.insert({-i,next++});
    }
    int N = next+1;
    vector<ll> yAxis(N,0);

    vector<ll> st[N];

    fore(i,0,n){
        pair<ll,ll> nuevo = {trad[rectangles[i].fst], trad[rectangles[i].snd]};
        rectangles[i] = nuevo;
        st[rectangles[i].fst].pb(i);
        yAxis[rectangles[i].fst]++;
        yAxis[rectangles[i].snd+1]--;
    }

    fore(i,0,N-1){
        yAxis[i+1] +=  yAxis[i];
    }

    STree rmq(N);rmq.init(yAxis);

    ll ans = 0;

    fore(i,0,N-1){
        fore(j,0,SZ(st[i])){
            int ini = (rectangles[st[i][j]]).fst;
            int fin = (rectangles[st[i][j]]).snd;
            rmq.upd(ini,fin+1,-1);
        }
        ll q = rmq.query(0,N);
        ll Max = q+yAxis[i];
        ans = max(Max,ans);
    }

    cout<<ans<<"\n";
    return 0;
}
