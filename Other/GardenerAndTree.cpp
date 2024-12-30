#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> g[n];
        vector<int> res(n);
        vector<int> deg(n);
        fore(i,0,n-1){
            int u,v;cin>>u>>v;u--;v--;
            g[u].pb(v);
            g[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        fore(i,0,n)if(deg[i]==1){res[i]=1;q.push(i);}
        while(!q.empty()){
            int c = q.front();q.pop();
            for(auto nei : g[c]){
                if(deg[nei]>1){
                    deg[nei]--;
                    if(deg[nei]==1){res[nei]=res[c]+1;q.push(nei);}
                    
                }
            }
        }
        int ans = n;
        fore(i,0,n){if(res[i]<=k)ans--;}
        cout<<ans<<endl;

    }
    
    return 0;
}
