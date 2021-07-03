#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(), s.end()
#define SZ(s) ((int)(x).size())
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define PI acos(-1)

typedef long long ll;
using namespace std;

int main()
{
    FIN;
    int t;
    cin >> t;
    while (t--)
    {
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
// #endif
        double n, l, d, g;
        cin >> n >> l >> d >> g;
        double apo = l / (2 * tan(PI / n));
        double ap = n * l * apo / 2;
        double ac = PI * d * g * d * g;
        double ans = ac + ap + n * d * g * l;
        cout<<fixed<<setprecision(9);
        cout << ans << "\n";
    }
    return 0;
}