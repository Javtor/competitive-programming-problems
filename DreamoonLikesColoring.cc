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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> cap(m);
    vector<int> ans(m,-1);
    vector<pair<int, int>> colors;
    fore(i, 0, m)
    {
        cin >> cap[i];
        colors.pb({cap[i], i});
    }
    int total = accumulate(ALL(cap), 0);
    if (n > total)
    {
        cout << -1;
        return 0;
    }
    reverse(ALL(colors));
 
    int minInd = (*(colors.begin())).snd;
    ans[minInd]=0;
    int cubierto = cap[minInd];
    total-=cap[minInd];
    cap[minInd]=0;
    colors.erase(colors.begin());
 
    if(n-cubierto < m-1){
        cout << -1;
        return 0;
    }
    if(m-1==0){
        cout << 1;
        return 0;
    }
    
    int maxPorColor = (n-cubierto) / (m-1);
 
    for (auto pi : colors)
    {
        ans[pi.snd] = cubierto;
        int aCubrir = min(cap[pi.snd], maxPorColor);
        cubierto += aCubrir;
        cap[pi.snd] -= aCubrir;
    }
    int meFalta = n - cubierto;
 
    for (auto rit = colors.rbegin(); rit != colors.rend(); ++rit)
    {
        auto pi = *rit;
        int cubroExtra = min(cap[pi.snd],meFalta);
        meFalta-=cubroExtra;
        ans[pi.snd]+=meFalta;
    }
 
    vector<int> map(n,-1);
    fore(i,0,m){
        map[ans[i]]=i;
    }
    fore(i,0,n){
        if(map[i]==-1){
            map[i]=map[i-1];
        }
        ans[map[i]]=n-i;
    }
 
    fore(i,0,m){
        if(i!=0)cout<<" ";
        cout<<ans[i];
    }
 
    return 0;
}