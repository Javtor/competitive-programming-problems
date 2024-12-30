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
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

typedef ll tipo;
struct Line{tipo m,h;};
tipo inter(Line a, Line b){
    tipo x=b.h-a.h, y=a.m-b.m;
    return x/y+(x%y?!((x>0)^(y>0)):0);//==ceil(x/y)
}
struct CHT {
	vector<Line> c;
	bool mx;
	int pos;
	CHT(bool mx=0):mx(mx),pos(0){}//mx=1 si las query devuelven el max
	inline Line acc(int i){return c[c[0].m>c.back().m? i : sz(c)-1-i];}
	inline bool irre(Line x, Line y, Line z){
		return c[0].m>z.m? inter(y, z) <= inter(x, y)
                         : inter(y, z) >= inter(x, y);
	}
	void add(tipo m, tipo h) {//O(1), los m tienen que entrar ordenados
        if(mx) m*=-1, h*=-1;
		Line l=(Line){m, h};
        if(sz(c) && m==c.back().m) { l.h=min(h, c.back().h), c.pop_back(); if(pos) pos--; }
        while(sz(c)>=2 && irre(c[sz(c)-2], c[sz(c)-1], l)) { c.pop_back(); if(pos) pos--; }
        c.pb(l);
	}
	inline bool fbin(tipo x, int m) {return inter(acc(m), acc(m+1))>x;}
	tipo eval(tipo x){
		int n = sz(c);
		//query con x no ordenados O(lgn)
		int a=-1, b=n-1;
		while(b-a>1) { int m = (a+b)/2;
			if(fbin(x, m)) b=m;
			else a=m;
		}
		return (acc(b).m*x+acc(b).h)*(mx?-1:1);
        //query O(1)
		while(pos>0 && fbin(x, pos-1)) pos--;
		while(pos<n-1 && !fbin(x, pos)) pos++;
		return (acc(pos).m*x+acc(pos).h)*(mx?-1:1);
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
    int n,m,p;
     cin>>n>>m>>p;
    ll dist[n], ps[n];
    dist[0] = ps[0] = 0;
    fore(i,1,n){ cin>>dist[i]; ps[i] = ps[i-1]+dist[i];}
    vector<ll> s;
    fore(i,0,m){
        ll h,t; cin>>h>>t; h--;
        s.pb(t-ps[h]);
    }
    vector<ll> a;
    sort(ALL(s));
    a.pb(s[0]);
    fore(i,1,m) a.pb(a.back()+s[i]);
    // s -> valores a -> sumas parciales
    // ll f[p+1][m];
    vector<vector<ll>> f(p+1,vector<ll>(m));
    fore(i,0,p+1){
        CHT cht(0);
        fore(j,0,m){
            if(j==0 ||i==0){
                f[i][j]=0;
                if(j==0 && i !=0) cht.add(-j,f[i-1][j]+a[j]);
                continue;
            }
            ll ans = j*s[j]-a[j];
            ans+=cht.eval(s[j]);
            f[i][j]=ans;
            cht.add(-j,f[i-1][j]+a[j]);

        }
    }
    cout<<f[p][m-1];
    return 0;
}
