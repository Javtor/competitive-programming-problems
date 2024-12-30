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
    int n;cin>>n;
    vector<ll> b(n);
    fore(i,0,n){
        cin>>b[i];
    }
    vector<ll> dp(n+15,1e18);
    dp[0]=0;
    fore(i,0,n){
        ll c = dp[i]+120;
        ll t = b[i]+1800;
        fore(k,i,n){
            if(b[k]<=t){
                c+=20;
                t+=20;
            } else
            {
                c+=b[k]-t+20;
                t= b[k]+20;
            }
            dp[k+1] = min(dp[k+1],c);            
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
