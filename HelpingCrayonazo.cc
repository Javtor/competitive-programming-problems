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
const int MAXN = 1e6+15;
ll cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}

map<ll,ll> fact(ll n){  // must call init_cribe before
	map<ll,ll> r;
	fore(i,2,MAXN){
        if(cr[i]==-1){
            while(n%i==0){
                n/=i;
                r[i]++;
            }
        }
    }
    if(n>1)r[n]++;
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
    ll n;cin>>n;
    init_sieve();
    auto f = fact(n);
    if(n==1){cout<<"NO";return 0;}
    ll cnt = 0;
    for(auto p : f){
        if(p.snd&1LL)cnt++;
    }
    if(sz(f)==1 || cnt<2){cout<<"YES";return 0;}
    cout<<"NO";
    return 0;
}
