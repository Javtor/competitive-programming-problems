#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

const int MAXN = 2e5+5;
int len = 1;
int hijo[31*MAXN][2];
int s[31*MAXN];

void update(int n, int sum){
    int ac = 1, cual = 0;
    for(int i = 30;i>=0;i--){
        cual = (n>>i)&1;
        if(!hijo[ac][cual])
            hijo[ac][cual]=++len;
        s[ac]+=sum;
        ac=hijo[ac][cual];
    }
    s[ac]+=sum;
}

int query(int n){
    int ac = 1, cual = 0, ans = 0;
    for(int i = 30;i>=0;i--){
        cual = ((n>>i)&1)^1;
        if(s[hijo[ac][cual]])
            ans|=(1<<i);
        else cual^=1;
        ac=hijo[ac][cual];
    }
    return ans;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    mset(hijo,0);
    mset(s,0);
    int q;cin>>q;
    update(0,1);
    while(q--){
        char op;int n;cin>>op>>n;
        if(op=='+')update(n,1);
        else if(op=='-')update(n,-1);
        else cout<<query(n)<<'\n';
    }
    return 0;
}
