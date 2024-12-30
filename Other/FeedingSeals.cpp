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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n, c;
    cin >> n >> c;

    vector<ll> ws(n);

    fore(i, 0, n)
            cin >>
        ws[i];

    sort(ALL(ws));

    ll cap = 1e11;
    ll ans = 0;

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        ll sum = ws[l] + ws[r];
        if (sum <= c)
        {
            r--;
            l++;
        }
        else
        {
            r--;
        }
        ans++;
    }
    if (l == r)
        ans++;

    cout << ans;

    return 0;
}
