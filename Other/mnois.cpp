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

const int MAXN = 115;

ll dplis[MAXN][MAXN][MAXN];
ll dp[MAXN][MAXN];
vector<int> a;
int n;

ll lis(int ind, int to, int last){
    if(ind>to)return 0;
    ll &r = dplis[ind][to][last];
    if(r!=-1) return r;
    r = lis(ind+1,to,last);
    if(last==n||a[ind]>a[last]){
        r = max(r,1+lis(ind+1,to,ind));
    }
    return r;
}

ll go(int ind, int k){
    if(ind>=n)return 0;
    ll &r = dp[ind][k];
    if(r!=-1) return r;

    r = go(ind+1,k);//Voy al siguiente
    fore(i,ind,n){
        if(lis(ind,i,n)>=k){
            r = max(r,go(i+1,k)+lis(ind,i,n));
        }
    }

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
    int t;cin>>t;
    while(t--){
        cin>>n;
        mset(dplis,-1);
        mset(dp,-1);
        a.clear();
        fore(i,0,n){
            int nxt;cin>>nxt;
            a.pb(nxt);
        }
        fore(k,1,n+1){
            cout<<go(0,k);
            if(k<n)cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
