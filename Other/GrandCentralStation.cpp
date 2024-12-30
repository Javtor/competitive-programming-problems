#include <bits/stdc++.h>
#define pb push_back
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

typedef vector<int> vi;
auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));

const int MAXN = 3e5+15;

map<ll,ll> mp;
int n;
vi g[MAXN];
ll th[MAXN];
set<ll> ans;

ll f(ll x){
    if(!mp.count(x)){
        mp[x]=rnd();
    }
    return mp[x];
}

ll dfs(int ind, int par = -1){
    ll sum = 0;
    for(int i : g[ind]){
        if(i != par) sum+=dfs(i,ind);
    }
    return th[ind]=f(sum);
}

void go(int ind, int par = -1, ll hashP = 0){
    ll sum = hashP;
    for(int i : g[ind]){
        if(i != par) sum+=th[i];
    }
    ans.insert(f(sum));
    for(int i : g[ind]){
        if(i != par) go(i,ind,f(sum-th[i]));
    }

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
    cin>>n;
    fore(i,1,n){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);go(0);
    cout<<SZ(ans)<<endl;
    return 0;
}
