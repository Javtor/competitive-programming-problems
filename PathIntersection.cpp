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

const int K = 15;
vector<int> g[1<<K];int n;  // K such that 2^K>=n
bitset<1<<K> B[1<<K];

int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
    B[0][0]=1;
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
        B[y][y]=1;
        B[y]|=B[x];
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
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
    int t;cin>>t;
    int cs = 1;
    while(t--){
        fore(i,0,1<<K){
            g[i].clear();
            B[i].reset();
        }
        memset(F,0,sizeof(F));
        memset(D,0,sizeof(D));
        cout<<"Case "<<cs++<<":\n";
        cin>>n;
        fore(i,0,n-1){
            int u, v;cin>>u>>v;u--;v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        lca_init();
        int q;cin>>q;
        
        while(q--){
            int k;cin>>k;
            bitset<1<<K> bk;
            bool cambio = 1;
            while(k--){
                int a,b;cin>>a>>b;a--;b--;
                int l = lca(a,b);
                bitset<1<<K> bactual = (B[a]|B[b])^B[l];bactual[l]=1;
                if(cambio){
                    cambio = false;
                    bk = bactual;
                }else{
                    bk &= bactual;
                }
            }
            int numberof1 = bk.count();
            cout<<numberof1<<'\n';
        }
    }
    return 0;
}
