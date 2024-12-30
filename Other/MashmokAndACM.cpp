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
const int MAXN = 3000;
ll dp[MAXN+15][MAXN+15];
int n,k;
ll go(int ult, int lon){
    if(lon==k)return 1;
    ll &r = dp[ult][lon];
    if(r != -1) return r;
    r = 0;
    for(int i = ult; i <=n; i+=ult){
        r+=go(i,lon+1);
        r%=MOD;
    }
    r%=MOD;
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
    cin>>n>>k;
    mset(dp,-1);
    cout<<go(1,0);
    return 0;
}
