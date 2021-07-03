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
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)
 
typedef long long int ll;
 
using namespace std;
 
typedef vector<int> vi;
 
struct pt
{ // for 3D add z coordinate
    long double x, y;
    pt(long double x, long double y) : x(x), y(y) {}
    pt() {}
    long double norm2() { return *this * *this; }
    long double norm() { return sqrt(norm2()); }
    bool operator==(pt p) { return abs(x - p.x) < EPS && abs(y - p.y) < EPS; }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) const { return pt(x - p.x, y - p.y); }
    pt operator*(long double t) { return pt(x * t, y * t); }
    pt operator/(long double t) { return pt(x / t, y / t); }
    long double operator*(pt p) { return x * p.x + y * p.y; }
    //	pt operator^(pt p){ // only for 3D
    //		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
    long double angle(pt p)
    { // redefine acos for values out of range
        return acos(*this * p / (norm() * p.norm()));
    }
    pt unit() { return *this / norm(); }
    long double operator%(pt p) { return x * p.y - y * p.x; }
    // 2D from now on
    bool operator<(pt p) const
    { // for convex hull
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
    bool left(pt p, pt q)
    { // is it to the left of directed line pq?
        return (q - p) % (*this - p) > EPS;
    }
    pt rot(pt r) { return pt(*this % r, *this * r); }
    pt rot(long double a) { return rot(pt(sin(a), cos(a))); }
};
pt ccw90(1, 0);
pt cw90(-1, 0);
 
struct circle
{
    pt o;
    long double r;
    circle(pt o, long double r) : o(o), r(r) {}
    bool has(pt p) { return (o - p).norm() < r + EPS; }
    vector<pt> operator^(circle c)
    { // ccw
        vector<pt> s;
        long double d = (o - c.o).norm();
        if (d > r + c.r + EPS || d + min(r, c.r) + EPS < max(r, c.r))
            return s;
        long double x = (d * d - c.r * c.r + r * r) / (2 * d);
        long double y = sqrt(r * r - x * x);
        pt v = (c.o - o) / d;
        s.pb(o + v * x - v.rot(ccw90) * y);
        if (y > EPS)
            s.pb(o + v * x + v.rot(ccw90) * y);
        return s;
    }
    vector<pt> tang(pt p)
    {
        long double d = sqrt((p - o).norm2() - r * r);
        return *this ^ circle(p, d);
    }
    bool in(circle c)
    { // non strict
        long double d = (o - c.o).norm();
        return d + r < c.r + EPS;
    }
};
 
struct Cmp
{ // IMPORTANT: add const in pt operator -
    pt r;
    Cmp(pt r) : r(r) {}
    int cuad(const pt &a) const
    {
        if (a.x > 0 && a.y >= 0)
            return 0;
        if (a.x <= 0 && a.y > 0)
            return 1;
        if (a.x < 0 && a.y <= 0)
            return 2;
        if (a.x >= 0 && a.y < 0)
            return 3;
        assert(a.x == 0 && a.y == 0);
        return -1;
    }
    bool cmp(const pt &p1, const pt &p2) const
    {
        int c1 = cuad(p1), c2 = cuad(p2);
        if (c1 == c2)
            return p1.y * p2.x < p1.x * p2.y;
        return c1 < c2;
    }
    bool operator()(const pt &p1, const pt &p2) const
    {
        return cmp(p1 - r, p2 - r);
    }
};
 
vector<long double> intercircles(vector<circle> c)
{
    vector<long double> r(SZ(c) + 1); // r[k]: area covered by at least k circles
    fore(i, 0, SZ(c))
    {
        int k = 1;
        Cmp s(c[i].o);
        vector<pair<pt, int>> p = {
            {c[i].o + pt(1, 0) * c[i].r, 0},
            {c[i].o - pt(1, 0) * c[i].r, 0}};
        fore(j, 0, SZ(c)) if (j != i)
        {
            bool b0 = c[i].in(c[j]), b1 = c[j].in(c[i]);
            if (b0 && (!b1 || i < j))
                k++;
            else if (!b0 && !b1)
            {
                auto v = c[i] ^ c[j];
                if (SZ(v) == 2)
                {
                    p.pb({v[0], 1});
                    p.pb({v[1], -1});
                    if (s(v[1], v[0]))
                        k++;
                }
            }
        }
        sort(p.begin(), p.end(),
             [&](pair<pt, int> a, pair<pt, int> b) { return s(a.fst, b.fst); });
        fore(j, 0, SZ(p))
        {
            pt p0 = p[j ? j - 1 : SZ(p) - 1].fst, p1 = p[j].fst;
            long double a = (p0 - c[i].o).angle(p1 - c[i].o);
            r[k] += (p0.x - p1.x) * (p0.y + p1.y) / 2 + c[i].r * c[i].r * (a - sin(a)) / 2;
            k += p[j].snd;
        }
    }
    return r;
}
 
int main()
{
    FIN;
    vector<pair<pt, long double>> pts;
    int n;
    long double a;
    cin >> n >> a;
    fore(i, 0, n)
    {
        long double x, y, t;
        cin >> x >> y >> t;
        pts.pb({pt(x, y), t});
    }
    long double l = 0, r = 1e10;
    int times = 300;
    long double ans = 0;
    while (times--)
    {
        long double m = l+(r - l) / 2.0;
        ans = m;
        vector<circle> circles;
        fore(i, 0, n)
        {
            if (pts[i].snd <= m)
                circles.pb(circle(pts[i].first, m - pts[i].second));
        }
        long double area = intercircles(circles)[1];
        if (area <= a)
            l = m;
        else 
            r = m;
    }
    cout << fixed << setprecision(12) << ans<<endl;
    return 0;
}