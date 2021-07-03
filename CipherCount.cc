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

const int mod = 1e9+7;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    int a,k;cin>>a>>k;
    vector<ll> pot;
    pot.pb(1);
    fore(i,1,k+1){
        pot.pb(pot[i-1]*a);
        pot[i]%=mod;
    }
    vector<ll> dp(k+1);
    ll ans = 0;
    fore(i,1,k+1){
        dp[i]+=pot[i];
        dp[i]%=mod;
        ans+=dp[i];
        ans%=mod;
        for(int j = 2*i; j<k+1;j+=i){
            dp[j] = ((dp[j]-dp[i])%mod + mod)%mod;
        }
    }
    cout<<ans<<endl;
}
