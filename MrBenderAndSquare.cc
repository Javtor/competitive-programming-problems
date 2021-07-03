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
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

ll n;



ll sumaPasa(ll t, ll i)
{
    ll pasa = max(0LL, t - (n - i));
    return pasa*pasa;
}

ll sumaEsq(ll t, ll i, ll j)
{

    ll arr = max(0LL, t - (n - i));
    ll der = max(0LL, t - (n - j));
    ll corteHoriz = max(0LL, (arr - 1) - (n - j));
    return corteHoriz * (corteHoriz + 1) / 2;
}

ll solve(ll t, ll x, ll y)
{

    ll base = 2 * t * t + 2 * t + 1;

    ll xAlt = n - x + 1;
    ll yAlt = n - y + 1;

    base -= sumaPasa(t, xAlt); // arriba
    base -= sumaPasa(t, x); // abajo
    base -= sumaPasa(t, yAlt); // izq
    base -= sumaPasa(t, y); // der

    base += sumaEsq(t,xAlt,y); //arriba der
    base += sumaEsq(t,y,x); // abajo der
    base += sumaEsq(t,x,yAlt); // abajo izq
    base += sumaEsq(t,yAlt,xAlt); // abajo izq

    return base;
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
    ll c, x, y;
    cin >> n >> x >> y >> c;
    ll l = 0, r = 1e8+15;
    ll ans = 0;
    while(l<=r){
        ll m = r - (r-l)/2;
        ll pos = solve(m,x,y);
        if(pos>=c){
            ans = m;r = m-1;
        } else l = m+1;
    }
    // ll asd = solve(10,3,8);
    cout<<ans;
    return 0;
}
