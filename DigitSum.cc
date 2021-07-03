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
const int MOD = 1e9+7;
const int MAXN = 1e4+10;

string k;
int d;
ll dp[MAXN][110][2];

ll go(int pos, int mod, int menor){
    if(pos == SZ(k)) return mod ==0;
    ll &r = dp[pos][mod][menor];
    if(r!=-1) return r;
    r = 0;
    int act = k[pos]-'0';
    fore(i,0,10){
        if(menor || i<act)
            r+=go(pos+1,(mod+i+d)%d,1);
        else if(i==act){
            r+=go(pos+1,(mod+i+d)%d,0);
        }
        r%=MOD;
    }
    return r%MOD;
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

    cin>>k;
    cin>>d;
    mset(dp,-1);
    cout<<(go(0,0,0)-1+MOD)%MOD<<endl;
    return 0;
}
