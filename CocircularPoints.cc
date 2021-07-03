#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;
const double EPS = 1e-6;

// double inf
const double DINF = numeric_limits<double>::infinity();

struct pt
{ // for 3D add z coordinate
    double x, y;
    pt(double x, double y) : x(x), y(y) {}
    pt() {}
    double norm2() { return *this * *this; }
    double norm() { return sqrt(norm2()); }
    bool operator==(pt p) { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    pt operator*(double t) { return pt(x * t, y * t); }
    pt operator/(double t) { return pt(x / t, y / t); }
    double operator*(pt p) { return x * p.x + y * p.y; }
    double angle(pt p)
    { // redefine acos for values out of range
        return acos(*this * p / (norm() * p.norm()));
    }
    pt unit() { return *this / norm(); }
    double operator%(pt p) { return x * p.y - y * p.x; }
    // 2D from now on
    pt rot(pt r) { return pt(*this % r, *this * r); }
};
pt ccw90(1, 0);
pt cw90(-1, 0);

struct ln
{
    pt p, pq;
    ln(pt p, pt q) : p(p), pq(q - p) {}
    ln() {}
    bool has(pt r) { return dist(r) <= EPS; }
    bool seghas(pt r) { return has(r) && (r - p) * (r - (p + pq)) <= EPS; }
    bool operator/(ln l) { return abs(pq.unit() % l.pq.unit()) <= EPS; } // 2D
    bool operator==(ln l) { return *this / l && has(l.p); }
    pt operator^(ln l)
    {
        if (*this / l)
            return pt(DINF, DINF);
        pt r = l.p + l.pq * ((p - l.p) % pq / (l.pq % pq));
        return r;
    }
    double angle(ln l) { return pq.angle(l.pq); }
    pt proj(pt r) { return p + pq * ((r - p) * pq / pq.norm2()); }
    pt ref(pt r) { return proj(r) * 2 - r; }
    double dist(pt r) { return (r - proj(r)).norm(); }

    ln rot(pt a) { return ln(p, p + pq.rot(a)); } // 2D
};
ln bisector(pt p, pt q)
{
    return ln((p + q) * .5, p).rot(ccw90);
}
struct circle
{
    pt o;
    double r;
    circle(pt o, double r) : o(o), r(r) {}
    circle(pt x, pt y, pt z)
    {
        o = bisector(x, y) ^ bisector(x, z);
        r = (o - x).norm();
    }
    bool has(pt p){return fabs((o-p).norm()-r)<=EPS;}
};

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n)
    {
        int ans = min(2,n);
        vector<pt> points;
        int t = n;
        while (t--)
        {
            int x, y;
            cin >> x >> y;
            points.pb(pt(x, y));
        }

        fore(i, 0, n)
        {
            fore(j, i + 1, n)
            {
                fore(k, j + 1, n)
                {
                    circle cir = circle(points[i], points[j], points[k]);
                    pt o = cir.o;
                    double dist = cir.r;
                    int cnt = 0;
                    fore(p, 0, n)
                    {
                        if(cir.has(points[p])){
                            cnt++;
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cin >> n;
        cout << ans << "\n";
    }
    return 0;
}
