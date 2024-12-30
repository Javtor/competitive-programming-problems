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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int q;cin>>q;
    while(q--){
        int f;cin>>f;
        // vector<vector<int>> kb(f,vector<int>(100));
        vector<int> eol(f);
        fore(i,0,f){
            int s;cin>>s;
            eol[i]=s;
        }
        int rc,cc;cin>>rc>>cc;rc--;
        int rm,cm;cin>>rm>>cm;rm--;
        vector<vector<int>> g(f*100);
        fore(i,0,f){
            fore(j,0,eol[i]+1){
                int cur = 100*i+j;
                //Izq
                if(j)g[cur].pb(cur-1);
                else if(i) g[cur].pb(100*(i-1)+eol[i-1]);

                //Der
                if(j<eol[i])g[cur].pb(cur+1);
                else if(i<f-1) g[cur].pb(100*(i+1));

                //Arr
                if(i){
                    g[cur].pb(100*(i-1)+min(eol[i-1],j));
                }

                if(i<f-1){
                    g[cur].pb(100*(i+1)+min(eol[i+1],j));
                }

            }
        }
        int cursor = rc*100+cc;
        int mist = rm*100+cm;
        vector<bool> vis(sz(g));
        vector<int> d(sz(g));
        int u = cursor;
        d[u]=0;
        queue<int> q;
        q.push(u);
        vis[u]=1;
        while(!q.empty()){
            u = q.front();q.pop();
            
            for(auto v:g[u]){
                // if(v==431)
                //     int asd = 4;
                if(!vis[v]){
                    vis[v]=1;
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        cout<<d[mist]<<endl;
        int asd = 3;
    }
    return 0;
}
