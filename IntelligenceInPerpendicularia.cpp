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

    int n;cin>>n;
    ll per = 0;
    ll a1,b1;cin>>a1>>b1;
    ll l = a1, r = a1, u = b1, d = b1;
    ll ap = a1, bp = b1;
    fore(i,1,n){
        ll a,b;cin>>a>>b;
        l = min(a,l);
        r = max(a,r);
        u = max(b,u);
        d = min(b,d);
        per += abs(a-ap + b-bp);
        ap = a, bp = b;
    }
    per += abs(a1-ap + b1-bp);
    per -= (2*abs(l-r)+2*abs(u-d));
    cout<<per<<endl;
    return 0;
}
