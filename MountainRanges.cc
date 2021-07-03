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
    int maxT = 0;
    int max2 = 0;
    int n, x;
    cin >> n >> x;
    int last = 10000;
    while (n--)
    {
        int next;
        cin >> next;
        // cerr << next-last;
        if (next - last <= x)
        {
            max2++;
        }
        else
        {
            max2 = 1;
        }
        last = next;
        maxT = max(maxT, max2);
    }
    cout << maxT;
    return 0;
}
