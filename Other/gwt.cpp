#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int N=200;
const int K=22;

int w[N][N];
int seen[N];

int dp[1<<K];

int get(const VI& v, int k, int mask) {
  int& x = dp[mask];
  if (x!=-1) return x;
  if (k==v.size()) return x=0;
  if (mask&(1<<k)) return get(v,k+1,mask);
  else {
    x=1000000000;
    mask|=(1<<k);
    for (int i=0;i<v.size();++i) {
      if (mask&(1<<i)) continue;
      x=min(x,w[v[i]][v[k]]+get(v,k+1,mask|(1<<i)));
    }
  }
  return x;
}

int match(const VI& v) {
  memset(dp,-1,sizeof(dp));
  return get(v,0,0);
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
  int n,m;
  cin >> n >> m;
  VVI g(n);
  for (int i=0;i<n;++i) g[i].push_back(i);
  for (int i=0;i<m;++i) {
    int a,b,ww;
    cin >> a >> b >> ww;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    w[a][b]=w[b][a]=ww;
  }
  memset(seen,0,sizeof(seen));
  int ans=0;
  for (int i=0;i<n;++i) {
    if (g[i].size()&1) {
      cout << "impossible" << endl;
      return 0;
    }
    if (seen[i]) continue;
    for (int v : g[i]) seen[v]=true;
    ans += match(g[i]);
  }
  cout << ans << endl;
}
