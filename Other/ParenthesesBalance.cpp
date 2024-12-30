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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n;
    cin >> n;
    while (n--)
    {
        int p = 0, b = 0;
        bool pos = 1;
        string s;
        cin >> s;
        fore(i, 0, SZ(s))
        {
            char c = s[i];
            if (c == '(') p++;
            if (c == '[') b++;
            if (c == ')') p--;
            if (c == ']') b--;
            if(p<0||b<0)pos=0;
        }
        cout<<((pos&&p==0&&b==0)?"Yes":"No")<<endl;
    }
    return 0;
}
