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


int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    ll l=1e18,r=-1e18,u=-1e18,d=1e18;
    int n;cin>>n;
    fore(i,0,n){
        ll x,y,h;cin>>x>>y>>h;
        l=min(l,x-h);r=max(r,x+h);u=max(u,y+h);d=min(d,y-h);
    }
    if(u-d>=r-l){
        r+=(u-d)-(r-l);
    } else {
        u+=(r-l)-(u-d);
    }
    if((r-l)&1){
        r++;u++;
    }
    cout<<(r+l)/2<<' '<<(u+d)/2<<' '<<(r-l)/2<<endl;
    return 0;
}
