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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;
    ll prefs[m][m];
    ll g[m][m];
    memset(prefs, 0, sizeof(prefs));
    fore(i, 0, n)
    {
        vector<int> pref(m);
        fore(j, 0, m)
        {
            cin >> pref[j];
        }
        fore(j, 0, m)
        {
            fore(k, 0, m) if (pref[j] != 0 && (pref[j] < pref[k] || pref[k] == 0))
                prefs[j][k]++;
        }
    }
    fore(i, 0, m) fore(j, 0, m) if (prefs[i][j] > prefs[j][i]) g[i][j] = prefs[i][j];
    else g[i][j] = 0;

    fore(k, 0, m) fore(i, 0, m) fore(j, 0, m)
        g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));

    int cnt = 0;
    fore(i, 0, m)
    {
        bool esmax = true;
        fore(j, 0, m)
        {
            if (g[j][i] > g[i][j])
            {
                esmax = false;
                break;
            }
        }
        if (esmax)
        {
            if (cnt)
                cout << " ";
            cout << (i + 1);
            cnt++;
        }
    }

    cout << "\n";
    return 0;
}
