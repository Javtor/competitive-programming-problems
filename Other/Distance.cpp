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

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    
    int N,K,L;
    cin >> N>>K>>L;
    
    vector<pair<int,int> > g [K];  // u->[(v,cost)]
    ll dist[K];
    vector<int> pros;
    vector<int> cualPro(K,-1);
    set<int> prosS;
    ll ans = 1e17;

    fore(i,0,N){
        int next;cin>>next;
        if(prosS.find(next-1)!=prosS.end()){
            ans = 0;
        }
        pros.pb(next-1);
        cualPro[next-1]=next-1;
        prosS.insert(next-1);
    }

    fore(i,0,L){
        int B,C,D;cin>>B>>C>>D;
        B--;C--;
        g[B].pb({C,D});
        g[C].pb({B,D});
    }

    memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
    fore(i,0,pros.size()){
	    dist[pros[i]]=0;q.push(mp(0,pros[i]));
    }
	while(!q.empty()){
		int x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
            
			if(dist[y]<0||dist[x]+c<dist[y]){
                cualPro[y]=cualPro[x];
				dist[y]=dist[x]+c,q.push(mp(-dist[y],y));
            }
		}
	}

    fore(i,0,K){
        fore(j,0,g[i].size()){
            if(cualPro[i]!=-1&&cualPro[g[i][j].first]!=cualPro[i]){
                ll distAc = dist[g[i][j].first]+dist[i]+g[i][j].snd;
                ans = min(ans,distAc);
            }
        }
    }


    cout<<(ans*3);

    return 0;
}
