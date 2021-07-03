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

    ll n;cin>>n;
    ll p2 = 0, p5 = 0;
    while((n&1) == 0){
        p2++;
        n=n>>1;
    }
    while(n%5 == 0){
        p5++;
        n/=5;
    }
    vector<ll> pows;
    // vector<ll> val2;
    vector<ll> v5;
    // val2.pb(1);
    v5.pb(1);
    fore(i,1,p5+1){
        v5.pb(5*v5[i-1]);
    }
    
    fore(i,0,p2+1)fore(j,0,p5+1){
        ll val2 = (1LL<<i);
        ll val5 = v5[j];
        ll val = val2*val5;
        pows.pb(val);
    }
    sort(ALL(pows));
    cout<<SZ(pows)<<endl;
    for(auto p : pows)cout<<p<<endl;
    return 0;
}
