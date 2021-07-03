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

int n;
ll xs, ys;
ll x[24], y[24];
ll dist(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ll dp[1<<24];
vector<int> path;
ll go(int mask){
    if (mask == (1<<n) - 1) {
        return 0;
    }
    ll &r =  dp[mask];
    if(r!=-1)return r;
    r = 1e18;
    int pr = 0;
    fore(i,0,n)if(!(mask&(1<<i))){pr=i;break;}
    ll tmp = 2*dist(xs,ys,x[pr],y[pr]);
    r = min(r, tmp+go(mask|(1<<pr)));
    fore(i,pr+1,n){
        if(mask&(1<<i))continue;
        tmp = dist(xs,ys,x[pr],y[pr]) + dist(xs,ys,x[i],y[i]) + dist(x[i],y[i],x[pr],y[pr]);
        r = min(r,tmp+go(mask|(1<<pr)|(1<<i)));
    }
    return r;
}
void cam(int mask){
    
    if (mask == (1<<n) - 1) {
        return;
    }
    int pr = 0;
    fore(i,0,n)if(!(mask&(1<<i))){pr=i;break;}
    ll tmp = 2*dist(xs,ys,x[pr],y[pr]);
    if(go(mask)==tmp+go(mask|(1<<pr))){
        path.pb(pr+1);
        path.pb(0);
        cam(mask|(1<<pr));
        return;
    }
    fore(i,pr+1,n){
        if(mask&(1<<i))continue;
        tmp = dist(xs,ys,x[pr],y[pr]) + dist(xs,ys,x[i],y[i]) + dist(x[i],y[i],x[pr],y[pr]);
        if(go(mask)==tmp+go(mask|(1<<pr)|(1<<i))){
            path.pb(pr+1);
            path.pb(i+1);
            path.pb(0);
            cam(mask|(1<<pr)|(1<<i));
            return;
        }
    }
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
    cin>>xs>>ys;
    cin>>n;
    fore(i,0,n){
        cin>>x[i]>>y[i];
    }
    mset(dp,-1);
    cout<<go(0)<<endl;
    path.pb(0);
    cam(0);
    fore(i,0,SZ(path)){
        cout<<path[i]<<' ';
    }
    return 0;
}
