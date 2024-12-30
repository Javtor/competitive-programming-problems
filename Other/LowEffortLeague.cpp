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
#define PI acos(-1)
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

typedef vector<double> vd;
typedef vector<int> vi;

const int MAXN = 15;

ll dp[1 << MAXN][MAXN];

vi s(MAXN);

ll cost(int a, int b)
{ // a gane a b

    if (s[a] > s[b ])
        return 0;
    a = s[a ];
    b = s[b];
    return (ll)abs(a - b) * (ll)abs(a - b);
}

int R;


int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    memset(dp, -1, sizeof(dp));
    cin >> R;
    int n = 1<<R;
    fore(i, 0, 1 << R) cin >> s[i];
    fore(i,0,n) dp[i][0]=0;

    int cuantos = 1;
    fore(i,1,R+1){
        fore(j,0,n)dp[j][i]=1e18;
        for(int j = 0; j < n;j+=cuantos*2){
            int l = j; int mid = l+cuantos; int r = mid+cuantos;
            fore(k,l,mid)fore(kk,mid,r){
                dp[k][i]=min(dp[k][i],dp[k][i-1]+dp[kk][i-1]+cost(k,kk));
                dp[kk][i]=min(dp[kk][i],dp[k][i-1]+dp[kk][i-1]+cost(kk,k));
            }
        }
        cuantos*=2;
    }
    cout << dp[0][R];
    return 0;
}
