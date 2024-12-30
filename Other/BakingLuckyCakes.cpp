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

const double EPS = 1e-9;

const double DINF=numeric_limits<double>::infinity();
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(t*x,t*y);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;} // 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
int sgn(double x){if(x<-EPS)return -1;return x>EPS;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return abs((r-p)%pq)<EPS;}
	bool operator/(ln l){return abs(pq%l.pq)<EPS;}
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection (2D)
		double s=l.pq%pq;
		if(abs(s)<EPS)return pt(DINF,DINF);
		return l.p+l.pq*((p-l.p)%pq/s);
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return sgn(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
	ln rot(double a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
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

    int n;cin>>n;
    map<ln,set<int>> mapa;
    vector<pt> pts;
    fore(i,0,n){
        ll x,y;cin>>x>>y;
        pts.pb(pt(x,y));
    }
    fore(i,0,n)fore(j,i+1,n){
        mapa[ln(pts[i],pts[j])].insert(i);
        mapa[ln(pts[i],pts[j])].insert(j);
    }
    int m = 0;
    for(auto e:mapa){
        m=max(m,SZ(e.second));
    }
    ll ans = 0;
    if(m/2 > n-m) ans = n-m;
    else ans = n/3;
    cout<<ans<<endl;
    return 0;
}
