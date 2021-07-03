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
#define MOD 10000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;
#define MAXN 1e6 + 5

using namespace std;

ll cr[(int)MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve()
{
    memset(cr, -1, sizeof(cr));
    fore(i, 2, MAXN) if (cr[i] < 0) for (ll j = 1LL * i * i; j < MAXN; j += i) cr[j] = i;
}

ll powerinfact(ll n, ll p)
{
    ll ans = 0;
    ll tmp = n;
    while (tmp)
    {
        ans += tmp / p;
        tmp /= p;
    }
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
    init_sieve();
    vector<ll> primes;
    fore(i, 2, MAXN)
    {
        if (cr[i] == -1)
            primes.pb(i);
    }
    ll n;
    cin >> n;
    while (n)
    {
        ll ans = 1;
        fore(j, 0, primes.size())
        {
            ll i = primes[j];
            if (i > n)
                break;
            ll power = powerinfact(n, i);
            power++;
            power = (power + 1) * power / 2;
            power%=MOD;
            ans*=power;
            ans %= MOD;
        }
        cout << ans << "\n";
        cin >> n;
    }
    return 0;
}
