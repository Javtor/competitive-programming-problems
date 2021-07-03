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

void dijkstra(int x, vector<ll> &dist, vector<vector<pair<int,int>>> &g){
	fore(i,0,SZ(dist))dist[i]=-1;
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
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
    int n,m;cin>>n>>m;
    int a,b,k;cin>>a>>b>>k;
    int last = 0;
    vector<vector<int>> trad(n,vector<int>(k+1,-1));
    vector<vector<pair<int,int>>> g((k+1)*n);
    fore(i,0,m){
        int u,v,w;cin>>u>>v>>w;
        fore(j,0,k+1){
            if(trad[u][j]==-1) trad[u][j]=last++;
            int nU = trad[u][j];
            if(j){ //Uso el ticket
                if(trad[v][j-1]==-1) trad[v][j-1]=last++;
                int nV = trad[v][j-1];
                g[nU].pb({nV,0});
            }
            //No uso el ticket
            if(trad[v][j]==-1) trad[v][j]=last++;
            int nV = trad[v][j];
            g[nU].pb({nV,w});
        }
    }

    vector<ll> distDesdeA((k+1)*n,-1);
    vector<ll> distDesdeB((k+1)*n,-1);
    vector<vector<ll>> distHastaA(k+1,vector<ll>((k+1)*n,-1));
    vector<vector<ll>> distHastaB(k+1,vector<ll>((k+1)*n,-1));

    dijkstra(trad[a][k],distDesdeA,g);
    dijkstra(trad[b][k],distDesdeB,g);

    vector<vector<pair<int,int>>> gInv((k+1)*n);
    fore(i,0,SZ(g))fore(j,0,SZ(g[i])){
        int u = g[i][j].fst;
        int v = i;
        gInv[u].pb({v,g[i][j].snd});
    }

    fore(i,0,k+1){
        dijkstra(trad[a][i],distHastaA[i],gInv);
        dijkstra(trad[b][i],distHastaB[i],gInv);
    }
    ll cty = 0;
    ll ans = 1e18;
    fore(i,0,n){
        if(i == a || i ==b) continue;
        // ll cur = 1e18;

        ll loDeA = 1e18;
        fore(k1,0,k+1){ // Llego al de la mitad con esto
            ll parte1 = distDesdeA[trad[i][k1]];
            if(parte1==-1)continue;
            fore(k2,0,k1+1){ //Vuelvo al principio con esto
                ll parte2 = distHastaA[k2][trad[i][k1]];
                if(parte2==-1)continue;
                loDeA = min(loDeA,parte1+parte2);
            }
        }
        if(loDeA == 1e18) continue;

        ll loDeB = 1e18;
        fore(k1,0,k+1){ // Llego al de la mitad con esto
            ll parte1 = distDesdeB[trad[i][k1]];
            if(parte1==-1)continue;
            fore(k2,0,k1+1){ //Vuelvo al principio con esto
                ll parte2 = distHastaB[k2][trad[i][k1]];
                if(parte2==-1)continue;
                loDeB = min(loDeB,parte1+parte2);
            }
        }
        if(loDeB == 1e18) continue;
        if(loDeA+loDeB < ans){
            cty = i;
            ans = loDeA+loDeB;
        }
    }

    if(ans == 1e18){
        cout<<">:("<<endl;
    } else cout<<cty<<' '<<ans<<endl;
    return 0;
}
