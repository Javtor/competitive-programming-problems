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
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        char c = s[n - 1];
        if (c == 'a')
        {
            cout << s.substr(0, n - 1) << "as";
        }
        else if (c == 'i' || c == 'y')
        {
            cout << s.substr(0, n - 1) << "ios";
        }
        else if (c == 'l')
        {
            cout << s.substr(0, n - 1) << "les";
        }
        else if (c == 'n')
        {
            cout << s.substr(0, n - 1) << "anes";
        }
        else if (s.substr(n - 2, 2) == "ne")
        {
            cout << s.substr(0, n - 2) << "anes";
        }
        else if (c == 'o')
        {
            cout << s.substr(0, n - 1) << "os";
        }
        else if (c == 'r')
        {
            cout << s.substr(0, n - 1) << "res";
        }
        else if (c == 't')
        {
            cout << s.substr(0, n - 1) << "tas";
        }
        else if (c == 'u')
        {
            cout << s.substr(0, n - 1) << "us";
        }
        else if (c == 'v')
        {
            cout << s.substr(0, n - 1) << "ves";
        }
        else if (c == 'w')
        {
            cout << s.substr(0, n - 1) << "was";
        }
        else
        {
            cout << s.substr(0, n) << "us";
        }

        cout << "\n";
    }
    return 0;
}
