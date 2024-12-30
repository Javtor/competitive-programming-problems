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
int N, L, A;
ll dp[2000 + 15];
vector<vector<int>> graph;

void dfs(int n)
{
    ll total = 0;
    if (n >= L)
    {
        total = 1;
        A++;
    }
    else
    {
        fore(i, 0, graph[n].size())
        {
            int next=graph[n][i];
            if(dp[next]==-1){
                dfs(next);
            } total += dp[next];
            total%=MOD;
        }
    }
    dp[n]=total;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> L;
    memset(dp, -1, sizeof(dp));
    A = 0;
    fore(i, 0, L)
    {
        int M;
        cin >> M;
        vector<int> actual;
        fore(j, 0, M)
        {
            int K;
            cin >> K;
            actual.pb(K - 1);
        }
        graph.pb(actual);
    }
    dfs(0);
    cout<<dp[0]<<" "<<A;
    return 0;
}
