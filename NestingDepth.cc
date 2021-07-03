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
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        string ans = "";
        string s;
        cin >> s;
        int curdepth = 0;
        fore(i, 0, s.size())
        {
            int next = s[i] - '0';
            if (curdepth < next)
            {
                int dif = next - curdepth;
                fore(j, 0, dif)
                {
                    ans += '(';
                    curdepth++;
                }
            }
            else if (curdepth > next)
            {
                int dif = curdepth - next;
                fore(j, 0, dif)
                {
                    ans += ')';
                    curdepth--;
                }
            }
            if (curdepth == next)
            {
                ans += next+'0';
            }
        }
        fore(j, 0, curdepth)
        {
            ans += ')';
        }
        cout << "Case #" << cs++ << ": " << ans << "\n";
    }

    return 0;
}
