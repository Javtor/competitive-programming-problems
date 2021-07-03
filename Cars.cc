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
#pragma GCC optimize("03")
#pragma GCC target("sse4")

struct rect{
    char d;
    double x1,y1,x2,y2,s;
};

bool
intersect(const rect &r1, const rect &r2)
{
    bool inter = r1.x1-EPS > r2.x2 ||
                     r2.x1-EPS > r1.x2 ||
                     r1.y1-EPS > r2.y2 ||
                     r2.y1-EPS > r1.y2 
                     ||
                     abs(r1.x1-r2.x2)<=EPS ||
                     abs(r2.x1-r1.x2)<=EPS ||
                     abs(r1.y1-r2.y2)<=EPS ||
                     abs(r2.y1-r1.y2)<=EPS;

    return !inter;
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
    double t;cin>>t;
    vector<rect> rs;
    fore(i,0,2){
        char d;double x,y,s,w,l;cin>>d>>x>>y>>s>>w>>l;
        double x1,x2,y1,y2;
        if(d=='N'||d=='S'){
            x1=x-w/2;x2=x+w/2;
            y1=y-l/2;y2=y+l/2;
        } else{
            x1=x-l/2;x2=x+l/2;
            y1=y-w/2;y2=y+w/2;
        }
        rect r;
        r.d=d;r.s=s;r.x1=x1;r.x2=x2;r.y1=y1;r.y2=y2;
        rs.pb(r);
    }
    rect r1 = rs[0], r2=rs[1];
    double total = 0;
    fore(i,0,1.2e4*t+1){
        if(intersect(r1,r2)){
            intersect(r1,r2);
            cout<<"crash\n";return 0;
        }
        double dt = 1/1.2e4;
        if(r1.d=='N' || r1.d=='S'){
            int dir = r1.d=='N'?1:-1;
            r1.y1 = r1.y1 + r1.s*dir*dt;
            r1.y2 = r1.y2 + r1.s*dir*dt;
        } else{
            int dir = r1.d=='E'?1:-1;
            r1.x1 = r1.x1 + r1.s*dir*dt;
            r1.x2 = r1.x2 + r1.s*dir*dt;
        }
        if(r2.d=='N' || r2.d=='S'){
            int dir = r2.d=='N'?1:-1;
            r2.y1 = r2.y1 + r2.s*dir*dt;
            r2.y2 = r2.y2 + r2.s*dir*dt;
        } else{
            int dir = r2.d=='E'?1:-1;
            r2.x1 = r2.x1 + r2.s*dir*dt;
            r2.x2 = r2.x2 + r2.s*dir*dt;
        }
    }
    // cout<<fixed<<setprecision(5)<<total;
    cout<<"safe\n";
    return 0;
}
