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
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));
const int MAXN = 5000;
ll F[MAXN];
ll INV[MAXN];
ll FI[MAXN];
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
ll inv(ll a){return pm(a,MOD-2);}
ll comb(ll n, ll k){
    if(n<k)return 0;
    return (F[n]*FI[k]%MOD*FI[n-k]%MOD)%MOD;
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
    F[0]=1;INV[1]=1;FI[0]=1;
    fore(i,1,MAXN){
        F[i]=(i*F[i-1])%MOD;
    }
    fore(i,2,MAXN){
        INV[i]=MOD-(ll)(MOD/i)*INV[MOD%i]%MOD;
    }
    fore(i,1,MAXN)FI[i]=FI[i-1]*INV[i]%MOD;
    ll n,m,k;cin>>n>>m>>k;
    ll ans = (comb(n-1,2*k)*comb(m-1,2*k))%MOD;
    cout<<ans;
    return 0;
}
