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
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cases;
    ll ans = 0;
    fore(i, 0, n)
    {
        ll ti, Ti, xi, ci;
        cin >> ti >> Ti >> xi >> ci;
        if(ti>=Ti) ans += ci + xi*(m);
        else if(ti+m<=Ti) ans += ci;
        else ans += min(ci+xi*m, (ll)(ci*ceil((double)m/(double)(Ti-ti))));
    }
    cout<<ans;
    return 0;
}
