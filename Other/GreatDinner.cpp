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

const ll mod = 1e9+7;
ll pm(ll a, ll e){
    ll r=1;
    while(e){
		if(e&1)r=(r*a)%mod;
		e>>=1;a=(a*a)%mod;
	}
    return r;
}
ll inv(int a){return pm(a,mod-2);}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    ll n, m;cin>>n>>m;
    ll ans = 1;
    fore(i,1,n+1){ans = (ans*i)%mod;}
    fore(i,1,m+1){ans = (ans*inv(2))%mod;}
    cout<<ans;
    return 0;
}
