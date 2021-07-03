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

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string B;
    cin >> B;
    int S;
    cin >> S;
    
    vector<int> indicesE;
    string b2 = B + B;
    fore(i, 0, b2.size())
    {
        if (b2[i] == 'E')
            indicesE.pb(i);
    }
    ll total = 0;
    if (indicesE.size() > 0)
    {
        fore(i, 0, B.size())
        {
            total += max(0, S + i - *lower_bound(all(indicesE), i) );
        }
    }
    cout << total;
    return 0;
}
