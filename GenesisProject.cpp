#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a, b) memset(a, b, sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(-1e5, 1e5), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int N;
    cin >> N;
    vector<pair<ll, ll>> pts;
    fore(i, 0, N)
    {
        ll x, y;
        cin >> x >> y;
        pts.pb({x, y});
    }
    sort(ALL(pts));
    int ans = 0;
    vector<pair<ll, ll>> pts2;
    fore(i, 0, pts.size()) fore(j, i + 1, pts.size())
    {
        pts2.pb({pts[i].fst + pts[j].fst, pts[i].snd + pts[j].snd});
    }
    sort(ALL(pts2));
    fore(i, 1, pts2.size())
    {
        if (pts2[i] == pts2[i - 1])
        {
            ans = 1;
            break;
        }
    }
    if (!ans){
        if(N<=3)cout<<0;
        else cout<<2;
    } else{
        cout<<1;
    }
    return 0;
}
