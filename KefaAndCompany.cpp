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
    ll n,d;cin>>n>>d;
    vector<ii> a(n);
    fore(i,0,n){
        int m,s;cin>>m>>s;a[i]={m,s};
    }
    sort(ALL(a));
    ll ans = 0;
    int i1 = 0, i2 = 0;
    ll curans = 0;
    while(i1 < n){
        if(i1==i2){
            curans = a[i1].snd;
            i2++; 
        }
        while(i2<n && a[i2].fst-a[i1].fst<d){
            curans+=a[i2].snd;           
            i2++;
        }
        ans = max(ans,curans);
        curans -= a[i1].snd;
        i1++;
    }
    cout<<ans;
    return 0;
}
