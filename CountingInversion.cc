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

ll nc2(ll a)
{
    ll ans = (a - 1) * a / 2;
    return ans;
}

ll trailingVec[20];

ll solveNotTrailing(int digits)
{
    ll &ans = trailingVec[digits];
    if (ans != -1)
        return ans;
    return ans = nc2(digits) * nc2(11) * pow(10, digits - 2);
}

ll solveTrailing(int digitos)
{
    ll falt = digitos;
    if (digitos <= 1)
        return 0;

    ll ans = solveTrailing(digitos - 1);
    ans += 9 * solveNotTrailing(digitos - 1);
    ans += nc2(9) * (falt - 1) * pow(10, falt - 2);
    return ans;
}

ll solve(int pos, const string &num)
{
    if (pos == num.size())
        return 0;
    ll ans = 0;
    int ub = num[pos] - '0';
    ll falt = SZ(num) - pos - 1;

    fore(i, 0, ub)
    {
        if (pos == 0 && i == 0)
            ans += solveTrailing(SZ(num) - pos - 1);
        else
        {
            ans += solveNotTrailing(SZ(num) - pos - 1);
            ans += (10 - (i + 1)) * (falt)*pow(10, falt - 1);
        }
    }
    ans += solve(pos + 1, num);
    return ans;
}

ll contar(ll max)
{
    ll cnt = 0;
    fore(i, 1, max)
    {
        string a = to_string(i);
        fore(i, 0, a.size())
        {
            fore(j, i+1, a.size())
            {
                if(a[i]<a[j])cnt++;
            }
        }
    }
    return cnt;
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
    memset(trailingVec, -1, sizeof(trailingVec));
    int t;
    cin >> t;
    while (t--)
    {
        ll xd = solve(0, "1000");
        ll aaaa = contar(1000);
        int asdfas = 0;
    }
    return 0;
}
