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

using namespace std;

ll prime[1000006];

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n = 1000005;
    memset(prime, 0, sizeof(prime));
    fore(i, 2, n + 1)
    {
        prime[i] = 1;
    }
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = 0;
        }
    }
    // fore(i,1,20){
    //     cerr<<i<<' '<<prime[i]<<endl;
    // }

    int a, b, k;
    cin >> a >> b >> k;
    int l = 1;
    int r = b - a + 1;
    int ans = -1;
    int parc[b + 1];
    parc[b] = prime[b];

    while (l <= r)
    {
        int m = (l + r) / 2;
        // int m = 4;
        for (int i = b - 1; i >= b - m + 1; i--)
        {
            parc[i] = prime[i] + parc[i + 1];
        }
        bool ok = !(parc[b - m + 1] < k);
        for (int i = b - m; i >= a; i--)
        {
            parc[i] = parc[i + 1] - prime[i + m] + prime[i];
            if (parc[i] < k)
                ok = false;
        }
        if (ok)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans;

    return 0;
}
