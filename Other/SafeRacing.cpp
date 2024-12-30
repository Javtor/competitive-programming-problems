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

ll mod = 123456789;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int l,s;cin>>l>>s;
    vector<ll> dp(l+15);
    dp[0]=1;
    ll suma = 1;
    fore(i,1,l+1){
        dp[i]=suma;
        suma+= dp[i];
        if(i-s>=0)suma-=dp[i-s];
        suma=(suma%mod+mod)%mod;
    }
    ll ans = 0;
    fore(n,1,s+1){
        ans+=dp[l-n]*n;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
