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
    // freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        bool posible = true;
        fore(i, 0, n)
        {
            cin >> a[i];
        }
        fore(i, 0, n)
        {
            cin >> b[i];
        }
        int dif = 0;
        bool primer = 0;
        int count = 0;
        fore(i, 0, n)
        {
            if (a[i] > b[i])
            {
                posible = false;
            }
            else 
            {
                int difAc = b[i] - a[i];
                if (difAc != dif)
                {
                    if (difAc != 0)
                        count++;
                }
                dif = difAc;
            }
        }
        if(!posible || count > 1){
            cout<<"NO\n";
        } else{
            cout<<"YES\n";
        }
    }
    return 0;
}
