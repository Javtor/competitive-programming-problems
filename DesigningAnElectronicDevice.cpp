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

struct frac {
    ll x, y;
    frac(ll a = 0, ll b = 1) {
        ll g = __gcd(a,b);
        x = a/g, y = b/g;
    }
    frac operator-(const frac &a) const {
        ll va = 0, vb = a.y / __gcd(y, a.y) * y;
        va = vb / y * x - vb / a.y * a.x;
        return frac(va, vb);
    }
    frac operator+(const frac &a) const {
        ll va = 0, vb = a.y / __gcd(y, a.y) * y;
        va = vb / y * x + vb / a.y * a.x;
        return frac(va, vb);
    }
    frac operator*(const frac a) const {
        ll g1 = __gcd(x, a.y), g2 = __gcd(a.x, y);
        ll va = 0, vb = 0;
        va = (x / g1) * (a.x / g2);
        vb = (y / g2) * (a.y / g1);
        return frac(va, vb);
    }
    bool operator<(const frac &a) const {
    	
    	double f1, f2;
    	f1 = 1.0 * x / y, f2 = 1.0 * a.x / a.y;
    	if (fabs(f1 - f2) < 1e-9)	return false;
    	return f1 < f2;
        
    }
};


vector<vector<frac>> probs;
vector<vi> costs;

frac dp[10][1000+15];
bool vis[10][1000+15];
int N,K;

frac go(int ind, int avail){
    if(ind>=N)
        return frac(0,1);
    if(vis[ind][avail])
        return dp[ind][avail];
    vis[ind][avail] = 1;
    frac ans = frac(1,1);
    fore(i,0,costs[ind].size()) {
        if(avail-costs[ind][i] <0)break;
        frac yofallo = probs[ind][i];
        frac nofallo = frac(1,1)-yofallo;
        frac sigfalla = go(ind+1,avail-costs[ind][i]);
        if((yofallo + (nofallo*sigfalla)) < ans) 
            ans = (yofallo + (nofallo*sigfalla));
    }
    return dp[ind][avail]=ans;
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
    while(cin>>N>>K){
        memset(vis,0,sizeof(vis));
        probs.resize(N);
        costs.resize(N);

        vector<int> maxreg(N);
        fore(i,0,N)cin>>maxreg[i];
        fore(i,0,N){probs[i].clear();costs[i].clear();fore(j,0,maxreg[i]){
            
            ll aa, bb, cc;cin>>aa>>bb>>cc;
            probs[i].pb(frac(aa,bb));costs[i].pb(cc);
        }}
        frac ans = go(0,K);
        cout<<ans.x<<'/'<<ans.y<<endl;
    }
    return 0;
}
