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

bool inCirc(ll x, ll y, ll r){
    return x*x+y*y<r*r;
}
bool onCirc(ll x, ll y, ll r){
    return x*x+y*y==r*r;
}

bool inSq(ll x, ll y, ll tx, ll ty, ll s){
    return x>tx && x<tx+s && y>ty && y<ty+s;
}
bool onSq(ll x, ll y, ll tx, ll ty, ll s){
    return (x==tx&&y>=ty&&y<=ty+s)
        ||(x==tx+s&&y>=ty&&y<=ty+s)
        ||(y==ty&&x>=tx&&x<=tx+s)
        ||(y==ty+s&&x>=tx&&x<=tx+s);
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
    ll x,y,r;cin>>x>>y>>r;
    ll tx,ty,s;cin>>tx>>ty>>s;
    tx-=x;
    ty-=y;
    
    if(
        (inCirc(tx,ty,r))
        ||(inCirc(tx+s,ty,r))
        ||(inCirc(tx,ty+s,r))
        ||(inCirc(tx+s,ty+s,r))
        ||(inSq(0,0,tx,ty,s))
        ||(inSq(r,0,tx,ty,s))
        ||(inSq(0,r,tx,ty,s))
        ||(inSq(-r,0,tx,ty,s))
        ||(inSq(0,-r,tx,ty,s))
    ){
        cout<<2<<endl;
        return 0;
    }
    if(
        (onCirc(tx,ty,r))
        ||(onCirc(tx+s,ty,r))
        ||(onCirc(tx,ty+s,r))
        ||(onCirc(tx+s,ty+s,r))
        ||(onSq(r,0,tx,ty,s))
        ||(onSq(0,r,tx,ty,s))
        ||(onSq(-r,0,tx,ty,s))
        ||(onSq(0,-r,tx,ty,s))
    ){
        cout<<1<<endl;
        return 0;
    }
     cout<<0<<endl;
    return 0;
}
