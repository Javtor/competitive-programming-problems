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

const int MAXN = 1e5+15;
int n;
vi x(MAXN), y(MAXN), px(MAXN), py(MAXN);
pair<ll,ll> pos = {-1e18,1e18};
pair<ll,ll> neg = {-1e18,1e18};

ll dist(ll X, ll Y){
    ll ans = 0;
    int indx = lower_bound(x.begin(),x.begin()+n,X)-x.begin();
    int indy = lower_bound(y.begin(),y.begin()+n,Y)-y.begin();
    if(indx){
        ans+=(indx*X-px[indx-1]);
    }
    if(indy){
        ans+=(indy*Y-py[indy-1]);
    }
    ans+= (px[n-1] - (indx?px[indx-1]:0)) - (n-indx)*X;
    ans+= (py[n-1] - (indy?py[indy-1]:0)) - (n-indy)*Y;
    return ans;
}

bool in(ll X, ll Y){
    return Y-X>=pos.fst && Y-X <=pos.snd
        && Y+X>=neg.fst && Y+X <=neg.snd;
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
    cin>>n;
    fore(i,0,n)cin>>x[i]>>y[i];
    ll d;cin>>d;
    
    fore(i,0,n){
        pos.fst = max(pos.fst, y[i]-x[i]-d);
        pos.snd = min(pos.snd, y[i]-x[i]+d);
        neg.fst = max(neg.fst, y[i]+x[i]-d);
        neg.snd = min(neg.snd, y[i]+x[i]+d);
    }
    sort(x.begin(),x.begin()+n);sort(y.begin(),y.begin()+n);

    fore(i,0,n){
        px[i]=x[i];
        py[i]=y[i];
        if(i){
            px[i]+=px[i-1];
            py[i]+=py[i-1];
        }
    }

    if(pos.fst>pos.snd || neg.fst>neg.snd){cout<<"impossible"<<endl;return 0;}
    ll xmed = x[n/2], ymed = y[n/2];
    ll ans = 1e18;
    
    if(in(xmed,ymed)) 
        ans = dist(xmed,ymed);

    vi pp = {pos.fst,pos.snd};
    vi nn = {neg.fst,neg.snd};
    
    fore(i,0,2)fore(j,0,2){
        ll xx = (nn[i]-pp[j])/2;
        ll yy = (nn[i]+pp[j])/2;
        if(in(xx,yy)) ans = min(ans,dist(xx,yy));
        if(in(xx,yy+1)) ans = min(ans,dist(xx,yy+1));
        if(in(xx+1,yy)) ans = min(ans,dist(xx+1,yy));
        if(in(xx+1,yy+1)) ans = min(ans,dist(xx+1,yy+1));
    }
    
    fore(i,0,n){
        fore(j,0,2){
            ll xx,yy;
            xx = x[i];
            //pos
            yy = xx+pp[j];
            if(in(xx,yy)) ans = min(ans,dist(xx,yy));
            //neg
            yy = -xx+nn[j];
            if(in(xx,yy)) ans = min(ans,dist(xx,yy));

            yy = y[i];
            //pos
            xx = yy-pp[j];
            if(in(xx,yy)) ans = min(ans,dist(xx,yy));
            //neg
            xx = -yy+nn[j];
            if(in(xx,yy)) ans = min(ans,dist(xx,yy));
        }
    }

    cout<<ans;
    return 0;
}
