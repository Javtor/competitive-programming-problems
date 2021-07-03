#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<double,double> pt;

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

const int MAXN = 1e3+10;
const int ternmax = 150;

double vw,vb;

pt G, D;
int n;
pt pts[MAXN];

double dist(pt a, pt b){
    return sqrt((b.fst-a.fst)*(b.fst-a.fst)+(b.snd-a.snd)*(b.snd-a.snd));
}
double tim(pt a, pt b, pt c){ //a bk b wk c
    double ans = dist(a,b)/vb;
    ans+=dist(b,c)/vw;
    return ans;
}

double ptln(pt st, pt en, pt crn1, pt crn2){
    //vert
    if(abs(crn1.fst-crn2.fst)<EPS){
        int it = ternmax;
        double l = min(crn1.snd,crn2.snd), r = max(crn1.snd,crn2.snd);
        while(it--){
            double m1 = l+(r-l)/3;
            double m2 = r-(r-l)/3;
            double cm1 = tim(st,{crn1.fst,m1},en);
            double cm2 = tim(st,{crn1.fst,m2},en);
            if(cm1<=cm2){
                r=m2;
            } else{
                l=m1;
            }          
        }
        double ans = tim(st,{crn1.fst,l},en);
        return ans; 
    } // hor
    int it = ternmax;
    double l = min(crn1.fst,crn2.fst), r = max(crn1.fst,crn2.fst);
    while(it--){
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        double cm1 = tim(st,{m1,crn1.snd},en);
        double cm2 = tim(st,{m2,crn1.snd},en);
        if(cm1<=cm2){
            r=m2;
        } else{
            l=m1;
        }          
    }
    double ans = tim(st,{l,crn1.snd},en);
    return ans;
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
    double X1,X2,Y1,Y2;
    cin>>vw>>vb>>X1>>Y1>>X2>>Y2;

    double xg,yg,xd,yd;
    cin>>xg>>yg>>xd>>yd;
    G = {xg,yg};D={xd,yd};
    
    pair<pt,pt> crn[4];
    crn[0] = {{X1,Y1},{X1,Y2}};
    crn[1] = {{X1,Y2},{X2,Y2}};
    crn[2] = {{X2,Y2},{X2,Y1}};
    crn[3] = {{X2,Y1},{X1,Y1}};

    cin>>n;
    fore(i,0,n){
        double x,y;
        cin>>x>>y;
        pts[i]={x,y};
    }
    double ans = dist(G,D)/vw;
    //two stations
    fore(i,0,n) fore(j,0,n) if(i != j)
    {
        double d1 = dist(G,pts[i])/vw;
        ans = min(ans,d1+tim(pts[i],pts[j],D));
    }
    
    fore(i,0,n) fore(j,0,4){
       ans = min(ans, dist(G,pts[i])/vw+ptln(pts[i],D,crn[j].fst,crn[j].snd)); //pt ln
       ans = min(ans, dist(D,pts[i])/vw+ptln(pts[i],G,crn[j].fst,crn[j].snd)); //ln pt
    }

    fore(i,0,4) fore(j,0,4){
        pt crn1 = crn[i].fst, crn2 = crn[i].snd, crn3 = crn[j].fst, crn4 = crn[j].snd;
        //vert
        if(abs(crn1.fst-crn2.fst)<EPS){
            int it = ternmax;
            double l = min(crn1.snd,crn2.snd), r = max(crn1.snd,crn2.snd);
            while(it--){
                double m1 = l+(r-l)/3;
                double m2 = r-(r-l)/3;
                pt pt1 = {crn1.fst,m1};
                pt pt2 = {crn1.fst,m2};
                double cm1 = dist(G,pt1)/vw+ptln(pt1,D,crn3,crn4);
                double cm2 = dist(G,pt2)/vw+ptln(pt2,D,crn3,crn4);
                ans = min(ans,cm1);
                if(cm1<=cm2){
                    r=m2;
                } else{
                    l=m1;
                }          
            }
        } else{// hor
            int it = ternmax;
            double l = min(crn1.fst,crn2.fst), r = max(crn1.fst,crn2.fst);
            while(it--){
                double m1 = l+(r-l)/3;
                double m2 = r-(r-l)/3;
                pt pt1 = {m1,crn1.snd};
                pt pt2 = {m2, crn1.snd};
                double cm1 = dist(G,pt1)/vw+ptln(pt1,D,crn3,crn4);
                double cm2 = dist(G,pt2)/vw+ptln(pt2,D,crn3,crn4);
                ans = min(ans,cm1);
                if(cm1<=cm2){
                    r=m2;
                } else{
                    l=m1;
                }          
            }
        }
    }

    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}
