#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

typedef vector<double> vd;
typedef vector<int> vi;

const int MAXN = 105;

int n, m;
vd X(MAXN);
vd Y(MAXN);

vi order(MAXN);
vector<vi> machines(MAXN);

double dist(int i, int j){
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}

double dp[MAXN][MAXN];

double solve(int ord, int mach){
    if(ord==n-1)return 0;
    double &r = dp[ord][mach];
    if(r != -1)return r;

    r = 1e18;

    int nexty = order[ord+1];
    for(auto i : machines[nexty]){
        r = min(r,dist(mach,i)+solve(ord+1,i));
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
    fore(i,0,MAXN)fore(j,0,MAXN)dp[i][j]=-1;
    cin>>n;
    fore(i,0,n){
        cin>>order[i];order[i]--;
    }

    int m;cin>>m;
    double angle = (2*PI)/(double)m;
    fore(i,0,m){
        int typ; cin>>typ;typ--;
        machines[typ].pb(i);
        X[i]=cos(i*angle);
        Y[i]=sin(i*angle);
    }

    X[m]=0;Y[m]=0;
    double ans = 1e18;
    for(auto i : machines[order[0]]){
        ans = min(ans,1+solve(0,i));
    }
    cout<<fixed<<setprecision(8)<<ans;
    return 0;
}
