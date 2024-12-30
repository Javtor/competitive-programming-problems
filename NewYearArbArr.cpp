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
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}
ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mulmod(r,a);
		e>>=1;a=mulmod(a,a);
	}
	return r;
}
ll inv(ll a){return pm(a,MOD-2)%MOD;}
ll k, pa, pb;
const int MAXN = 1000;
ll dp[10000][1015];

ll go(ll i, ll j){
    if(i+j>=k)return ((pa+pb)%MOD*inv(pb)-1LL+j+i)%MOD;//Aqui va algo que no sabemos
    ll &r = dp[i][j];
    if(r!=-1)return r;

    r = pa%MOD*go(i+1,j);
    r = r%MOD;
    r+=pb%MOD*(go(i,j+i));
    r = r%MOD;
    r*=inv(pa+pb);
    r = r%MOD;
    return r;
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
    cin>>k>>pa>>pb;
    mset(dp,-1);
    cout<<go(1,0);
    return 0;
}
