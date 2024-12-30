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
const int MAXN = 3005;

ll dp[MAXN][MAXN], pr[MAXN][MAXN];


int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int N;
    string s;
    cin>>N;
    cin>>s;
    dp[1][1] = 1;
    pr[1][1] = 1;
    fore(len, 2, N+1){ 
        fore(b,1,len+1){
            int L, R;
            if(s[len-2] == '<'){
                L = 0;
                R = b-1;
            } else
            {
                L = b;
                R = len-1;
            }
            dp[len][b] += pr[len-1][R] - pr[len-1][L-1];
            dp[len][b]%=mod;
            // fore(i,L,R+1){
            //     dp[len][b] += dp[len-1][i];
            //     dp[len][b]%=mod;
            // }

            pr[len][b] = pr[len][b-1] + dp[len][b];
        }
    }
    ll ans = 0;
    fore(i,1,N+1){
        ans = (ans + dp[N][i])%mod;
    }
    cout<<((ans)%mod+mod)%mod;
    return 0;
}
