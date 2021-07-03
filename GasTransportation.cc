#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e18;
const tc INFCOST=1e18;
struct MCF{
    int n;
    vector<tc> prio,pot; vector<tf> curflow; vector<int> prevedge,prevnode;
    priority_queue<pair<tc,int>, vector<pair<tc,int>>, greater<pair<tc,int>>> q;
    struct edge{int to, rev; tf f, cap; tc cost;};
    vector<vector<edge>> g;
    MCF(int n): n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n){}
    void add_edge(int s, int t, tf cap, tc cost){
        g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
        g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
    }
    pair<tf,tc> get_flow(int s, int t){
        tf flow=0; tc flowcost = 0;
        while(1){
            q.push({0,s});
            fore(i,0,SZ(prio)) prio[i]=INFCOST;
            prio[s]=0; curflow[s]=INFFLOW;
            while(SZ(q)){
                auto cur = q.top();
                tc d= cur.fst;
                int u = cur.snd;
                q.pop();
                if(d!=prio[u]) continue;
                for(int i = 0; i < SZ(g[u]); i++){
                    edge &e = g[u][i];
                    int v=e.to;
                    if(e.cap<=e.f) continue;
                    tc nprio = prio[u]+e.cost+pot[u]-pot[v];
                    if(prio[v]>nprio){
                        prio[v]=nprio;
                        q.push({nprio,v});
                        prevnode[v]=u; prevedge[v]=i;
                        curflow[v]=min(curflow[u],e.cap-e.f);
                    }
                }
            }
            if(prio[t]==INFCOST)break;
            fore(i,0,n) pot[i]+=prio[i];
            tf df=min(curflow[t], INFFLOW-flow);
            flow+=df;
            for(int v=t; v!= s; v=prevnode[v]){
                edge &e =g[prevnode[v]][prevedge[v]];
                e.f+=df; g[v][e.rev].f-=df;
                flowcost+=df*e.cost;
            }
        }
        return {flow,flowcost};
    }
};

int n,m; ll c;

int main() {FIN;
    freopen("gas.in", "r", stdin);
    freopen("gas.out", "w", stdout);
    cin>>n>>m>>c;
    vector<pair<pair<int,int>, ll>> edges;
    int dega = 0, degb = 0;
    fore(i,0,m){
        int a,b; ll w; cin>>a>>b>>w; a--; b--;
        edges.pb({{a,b},w});
        if(a == 0 || b == 0) dega++;
        if(a == n-1 || b == n-1) degb++;
    }
    int l = 1, r = min(dega,degb);
    int res;
    while(l<=r){
        int mid = (l+r)/2;
        MCF flow(n+2);
        fore(i,0,m){
            int a = edges[i].fst.fst, b = edges[i].fst.snd; ll w = edges[i].snd;
            flow.add_edge(a,b,1,w); flow.add_edge(b,a,1,w);
        }
        flow.add_edge(n,0,mid,0); flow.add_edge(n-1,n+1,mid,0);
        auto ans = flow.get_flow(n,n+1);
        if(ans.fst*c <= ans.snd) r = mid-1;
        else l = mid+1;
    }
    if(r == 0){cout<<"Fair\n"; return 0;}
    MCF flow(n+2);
    fore(i,0,m){
        int a = edges[i].fst.fst, b = edges[i].fst.snd; ll w = edges[i].snd;
        flow.add_edge(a,b,1,w); flow.add_edge(b,a,1,w);
    }
    flow.add_edge(n,0,r,0); flow.add_edge(n-1,n+1,r,0);
    auto ans = flow.get_flow(n,n+1);
    cout<<"Unfair\n";
    int cur = n;
    vector<int> fedges;
    while(cur != n-1){
        for(auto v: flow.g[cur]){
            if(v.f == ans.fst){
                if(cur != n){
                   fore(i,0,m){
                        int a = edges[i].fst.fst, b = edges[i].fst.snd;
                        if(a == cur && b == v.to){
                            fedges.pb(i); break;
                        }
                   }
                }
                cur = v.to;
                break;
            }
        }
    }
    cout<<SZ(fedges)<<"\n";
    for(auto x: fedges) cout<<x+1<<" "; cout<<"\n";
    return 0;
}

