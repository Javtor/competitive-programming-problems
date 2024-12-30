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
const int MAXN = 1e4 + 15;

int n;
vector<ll> h(MAXN, 0);
vector<ll> c(MAXN, 0);

ll cost(ll height)
{
    ll ans = 0;
    fore(i, 0, n)
    {
        ans += abs(height - h[i]) * c[i];
    }
    return ans;
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
        cin >> n;
        fore(i, 0, n)
        {
            cin >> h[i];
        }
        fore(i, 0, n)
        {
            cin >> c[i];
        }
        ll ans = 1e18;
        ll l = 0;
        ll r = 1e4+15;

        while (l <= r)
        {
            ll m1 = l+(r-l)/3;
            ll m2 = r-(r-l)/3;
            ans = cost(l);
            if(cost(m1)<cost(m2)){
                r=m2-1;
            } else{
                l=m1+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
