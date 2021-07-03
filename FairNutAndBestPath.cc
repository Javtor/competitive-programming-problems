#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
#define ll long long
using namespace std;
#define maxn 6
ll a[maxn];
ll dp[maxn];
ll ans = 0;
vector<pair<int, ll>> v[maxn];
ll dfs(int cur, int fa)
{
    ans = max(ans, dp[cur]);
    for (int i = 0; i < v[cur].size(); i++)
    {
        int son = v[cur][i].first;
        if (son == fa)
            continue;
        dfs(son, cur);
        ll val = dp[son] - v[cur][i].second;
        ans = max(ans, dp[cur] + val);
        dp[cur] = max(dp[cur], a[cur] + val);
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int u, vv, w;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> u >> vv >> w;
        v[u].push_back({vv, w});
        v[vv].push_back({u, w});
    }
    cout << dfs(1, 0) << endl;
    return 0;
}