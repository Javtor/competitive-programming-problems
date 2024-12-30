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

#define MAXN 1e5 + 15
typedef long long int ll;

using namespace std;

vector<ll> r(MAXN);
vector<ll> g(MAXN);
vector<ll> b(MAXN);

int nr, ng, nb;

ll c(ll x, ll y, ll z)
{
    return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

ll closestInR(ll x)
{
    auto it = lower_bound(r.begin(),r.begin()+nr, x);
    if (it == r.begin())
    {
        return *it;
    }
    else if (it == r.begin()+nr)
    {
        it--;
        return *it;
    }
    else
    {
        ll a = *it;
        it--;
        ll aa = *it;
        if (x - aa < a - x)
            return aa;
        else
            return a;
    }
}

ll closestInG(ll x)
{
    auto it = lower_bound(g.begin(),g.begin()+ng, x);
    if (it == g.begin())
    {
        return *it;
    }
    else if (it == g.begin()+ng)
    {
        it--;
        return *it;
    }
    else
    {
        ll a = *it;
        it--;
        ll aa = *it;
        if (x - aa < a - x)
            return aa;
        else
            return a;
    }
}

ll closestInB(ll x)
{
    auto it = lower_bound(b.begin(),b.begin()+nb, x);
    if (it == b.begin())
    {
        return *it;
    }
    else if (it == b.begin()+nb)
    {
        it--;
        return *it;
    }
    else
    {
        ll a = *it;
        it--;
        ll aa = *it;
        if (x - aa < a - x)
            return aa;
        else
            return a;
    }
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        cin >> nr >> ng >> nb;
        fore(i, 0, nr)
        {
            cin >> r[i];
        }
        fore(i, 0, ng)
        {
            cin >> g[i];
        }
        fore(i, 0, nb)
        {
            cin >> b[i];
        }
        sort(r.begin(), r.begin() + nr);
        sort(g.begin(), g.begin() + ng);
        sort(b.begin(), b.begin() + nb);
        ll ans = LLONG_MAX;
        fore(i,0,nr){
            ll cr = r[i];
            ll cb = closestInB(cr);
            ll cg = closestInG(cr);

            ans = min(ans,c(cr,cg,cb));
            ans = min(ans,c(cr,closestInG(cb),cb));
            ans = min(ans,c(cr,cg,closestInB(cg)));
            ans = min(ans,c(cr,cg,closestInB((cg+cr)/2)));
            ans = min(ans,c(cr,closestInG((cb+cr)/2),cb));
        }
        fore(i,0,ng){
            ll cr = g[i];
            ll cb = closestInB(cr);
            ll cg = closestInR(cr);

            ans = min(ans,c(cr,cg,cb));
            ans = min(ans,c(cr,closestInR(cb),cb));
            ans = min(ans,c(cr,cg,closestInB(cg)));
            ans = min(ans,c(cr,cg,closestInB((cg+cr)/2)));
            ans = min(ans,c(cr,closestInR((cb+cr)/2),cb));
        }
        fore(i,0,nb){
            ll cr = b[i];
            ll cb = closestInR(cr);
            ll cg = closestInG(cr);

            ans = min(ans,c(cr,cg,cb));
            ans = min(ans,c(cr,closestInG(cb),cb));
            ans = min(ans,c(cr,cg,closestInR(cg)));
            ans = min(ans,c(cr,cg,closestInR((cg+cr)/2)));
            ans = min(ans,c(cr,closestInG((cb+cr)/2),cb));
        }
        cout<<ans<<"\n";
    }

    return 0;
}
