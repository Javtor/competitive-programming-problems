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
const int MAXN  = 100;
ll dp[MAXN+10][MAXN+10];
int k,n;

ll go(int i, int ult){
    if(i == n) return ult == k;
    ll &r = dp[i][ult];
    if(r !=-1) return r;
    r = 0;
    fore(j,1,ult+1){
        r+=go(i+1,ult);

    }
    if(ult != k) r+=go(i+1,ult+1);
    return r;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
freopen("dinner.in", "r", stdin);
    freopen("dinner.out", "w", stdout);
#define endl '\n'
#endif
    mset(dp,-1);
    cin>>k>>n;
    cout<<go(0,0)<<endl;
    
    return 0;
}
