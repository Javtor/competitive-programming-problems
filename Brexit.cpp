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
    int c,p,x,l;cin>>c>>p>>x>>l;
    vector<vector<int>> g(c+1);
    vector<int> orig(c+1);
    vector<int> act(c+1);
    vector<bool> f(c+1,0);

    fore(i,0,p){
        int a,b;cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        orig[a]++;
        orig[b]++;
    }

    queue<int> adios;
    adios.push(l);
    f[l]=1;
    while(adios.size()){
        int u = adios.front();
        adios.pop();
        for(int v : g[u]){
            if(!f[v]){               
                act[v]++;
                if(act[v]>=(orig[v]+1)/2){
                    f[v]=1;
                    adios.push(v);
                }
            }
        }
    }
    
    
    if(f[x]) cout<<"leave"<<endl;
    else cout<<"stay"<<endl;
    return 0;
}
