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

    ll n, mx=0;cin>>n;
    vector<ll> a(n), mem(2000000+15);
    fore(i,0,n){cin>>a[i];mx=max(mx,a[i]);if(i)a[i]+=a[i-1];}
    ll q;cin>>q;
    while(q--){
        ll t;cin>>t;
        if(t<mx){cout<<"Impossible\n";continue;}
        if(mem[t]){cout<<mem[t]<<endl;continue;}
        ll cnt = 0;
        ll sm = t;
        ll l = 0;
        while(l<n){
            auto ub = upper_bound(ALL(a),sm);
            l = ub-a.begin();
            auto val = *(ub-1);
            sm = val+t;
            cnt++;
        }
        mem[t]=cnt;
        cout<<cnt<<endl;
    }
    return 0;
}
