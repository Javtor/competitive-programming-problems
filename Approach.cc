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

pair<double,double> nuevaPos(double x, double y, double x2, double y2, double d, double t){

    if(d<t) t = d;
    double nuevoX = x+t*(x2-x)/d;
    double nuevoY = y+t*(y2-y)/d;
    return {nuevoX,nuevoY};

}

double dist(double x1, double y1, double x2, double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
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
    double ax, ay, bx, by;
    double cx, cy, dx, dy;
    cin>>ax>>ay>>bx>>by;
    cin>>cx>>cy>>dx>>dy;

    double d1 = sqrt(dist(ax,ax,bx,by));
    double d2 = sqrt(dist(cx,cy,dx,dy));

    double l = 0, r = min(d1,d2);
    int times = 1e6;
    double ans = 0;
    while(times--){
        double t1 = l+(r-l)/3;
        double t2 = r - (r-l)/3;

        auto na = nuevaPos(ax,ay,bx,by,d1,t1);
        auto nc = nuevaPos(cx,cy,dx,dy,d2,t1);
        double m1 = dist(na.fst,na.snd,nc.fst,nc.snd);

        na = nuevaPos(ax,ay,bx,by,d1,t2);
        nc = nuevaPos(cx,cy,dx,dy,d2,t2);
        double m2 = dist(na.fst,na.snd,nc.fst,nc.snd);

        ans = min(m1,m2);

        if(m1<m2){
            r = t2;
        } else{
            l = t1;
        }

    }
    l = min(d1,d2), r = max(d1,d2)+10;
    times = 1e6;
    while(times--){
        double t1 = l+(r-l)/3;
        double t2 = r - (r-l)/3;

        auto na = nuevaPos(ax,ay,bx,by,d1,t1);
        auto nc = nuevaPos(cx,cy,dx,dy,d2,t1);
        double m1 = dist(na.fst,na.snd,nc.fst,nc.snd);

        na = nuevaPos(ax,ay,bx,by,d1,t2);
        nc = nuevaPos(cx,cy,dx,dy,d2,t2);
        double m2 = dist(na.fst,na.snd,nc.fst,nc.snd);

        ans = min(m1,m2);

        if(m1<m2){
            r = t2;
        } else{
            l = t1;
        }

    }

auto na = nuevaPos(ax,ay,bx,by,d1,6);
       auto nc = nuevaPos(cx,cy,dx,dy,d2,6);
        ans = dist(na.fst,na.snd,nc.fst,nc.snd);

    cout<<fixed<<setprecision(12)<<sqrt(ans)<<endl;
    int asd  = 4;
    return 0;
}
