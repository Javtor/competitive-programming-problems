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
struct circ{
    ll x, y, r;
};
struct pt{
    ll x, y;
};
bool in(const circ &c, const pt &p){
    return (p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y)<c.r*c.r;
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
    vector<bitset<1000>> cua(n);
    vector<vector<ll>> inter(n);
    vector<pt> pts;
    vector<circ> fnc;
    fore(i,0,n){
        ll x,y;cin>>x>>y;
        pt p; p.x=x;p.y=y;
        pts.pb(p);
    }
    fore(i,0,m){
        ll r,x,y;cin>>r>>x>>y;
        circ c; c.x=x;c.y=y;c.r=r;
        fore(j,0,n)if(in(c,pts[j]))
            cua[j].set(i);
    }
    fore(i,0,n)fore(j,0,n){
        inter[i].pb((cua[i]&cua[j]).count());
    }
    while(k--){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a>b)swap(a,b);
        ll c1 = cua[a].count();
        ll c2 = cua[b].count();
        ll ambos = 2*inter[a][b];
        cout<<(c1+c2-ambos)<<'\n';
    }
    return 0;
}
