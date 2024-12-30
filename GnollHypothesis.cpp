#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(), s.end()
#define fore(i, x, y) for (ll i = x; i < y; i++)
#define SZ(s) ((int)(x).size())
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
using namespace std;

double ncr(double n, double r)
{
    if (r < 0 || n < r)
        return 0;
    r = min(r, n - r);
    double ans = 1;
    fore(i, 1, r + 1)
    {
        ans *= (double)(n - i + 1) / (double)i;
    }
    return ans;
}

int main()
{
    double n, k;
    cin >> n >> k;
    vector<double> p(n, 0);
    double aa = ncr(5,3);
    fore(i, 0, n)
    {
        cin >> p[i];
    }
    fore(i, 0, n)
    {
        double ans = 0;
        fore(j, 0, n)
        {
            int index = (i-j+(int)n)%(int)n;
            ans+=p[index]*ncr(n-1-j,k-1)/ncr(n,k);
        }
        if(i!=0)cout<<" ";
        printf("%.9f",ans);
    }
    cout<<"\n";
    return 0;
}