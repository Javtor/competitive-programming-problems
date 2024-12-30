#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
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
typedef unsigned int uint;

using namespace std;

uint n, k, A, B;
vector<ll> av;

ll avengers(ll l, ll r)
{
    ll num = 0;
    int l1 = 0;
    // cerr << av.size();
    int r1 = k-1;
    int ind1 = -1;
    int ind2 = -1;
    while (l1 <= r1)
    {
        int mid = l1 + (r1 - l1) / 2;
        if (av[mid] >= l)
        {
            ind1 = mid;
            r1 = mid - 1;
        }
        else
        {
            l1 = mid + 1;
        }
    }
    l1 = 0;
    r1 = av.size() - 1;
    while (l1 <= r1)
    {
        int mid = l1 + (r1 - l1) / 2;
        if (av[mid] > r)
        {
            r1 = mid - 1;
        }
        else
        {
            ind2 = mid;
            l1 = mid + 1;
        }
    }

    if (ind1 != -1 && ind2 != -1 && ind2 >= ind1)
        num = ind2 - ind1 + 1;

    return num;
}

ll solve(ll l, ll r)
{
    uint nA = avengers(l, r);
    if (nA == 0)
        return A;
    ll parcial = (B * nA * (r - l + 1));
    if (l < r)
    {
        ll mid = l + (r - l) / 2;
        parcial = min(parcial, solve(l, mid) + solve(mid + 1, r));
    }
    return parcial;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    cin >> n >> k >> A >> B;
    vector<int> arr(n);
    fore(i, 0, k)
    {
        ll next;
        cin >> next;
        av.pb(next);
    }
    // foreach(ind,av){
        // cerr << *ind<<" ";
    // }
    sort(all(av));
    ll ans = solve(1, 1 << n);
    cout<<ans;
    return 0;
}
