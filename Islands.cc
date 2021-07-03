#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MAXN = 5E3+15;
const int MAXM = 1E4+15;
int n,m,k;

vector<ll> ix, iy, ir;
vector<ll> px, py, ph;

vi g[MAXN];
int lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	fore(_,0,g[u].size()){
		int v=g[u][_];
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}while(x!=u);
//		truth[qcmp]=(cmp[neg(u)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

double dist(int i, int j){
    double d = sqrt((ix[i]-ix[j])*(ix[i]-ix[j])+(iy[i]-iy[j])*(iy[i]-iy[j]));
    d-=(ir[i]+ir[j]);
    d+=200;
    return d;
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
    cin>>n>>m>>k;
    fore(i,0,n){
        ll x,y,r;cin>>x>>y>>r;
        ix.pb(x);iy.pb(y);ir.pb(r);
    }
    fore(i,0,m){
        ll x,y,h;cin>>x>>y>>h;
        px.pb(x);py.pb(y);ph.pb(h);
    }
    fore(i,0,m){
        int u;
        fore(j,0,n){
            if((px[i]-ix[j])*(px[i]-ix[j])+(py[i]-iy[j])*(py[i]-iy[j])<=ir[j]*ir[j]){
                u=j;break;
            }
        }
        fore(j,0,n){
            if(j != u && 
            (px[i]-ix[j])*(px[i]-ix[j])+(py[i]-iy[j])*(py[i]-iy[j])<=(ir[j]+k*ph[i])*(ir[j]+k*ph[i])){
                g[u].pb(j);
            }
        }
    }
    scc();
    set<int> gcmp[MAXN];
    vi indeg(qcmp);
    vi outdeg(qcmp);
    fore(i,0,n){  
        int u = cmp[i];      
        for(int j : g[i]){
            int v = cmp[j];
            if(u != v && !gcmp[u].count(v)){
                outdeg[u]++;indeg[v]++;
                gcmp[u].insert(v);
            }
        }
    }
    int U = -1,V=-1;
    bool pos = 1;
    if(qcmp==1){
        cout<<0<<endl;return 0;
    } else if(qcmp==2){
        U = 0, V = 1;
    } else
    {
        fore(i,0,qcmp){
            if(outdeg[i]==0){
                if(U> -1) pos = 0;
                U = i;
            }
            if(indeg[i]==0){
                if(V> -1) pos = 0;
                V = i;
            }
        } 
    } 
    if(!pos){
        cout<<"impossible"<<endl;return 0;
    }
    vi nu;vi nv;
    fore(i,0,n){
        if(cmp[i]==U)nu.pb(i);
        if(cmp[i]==V)nv.pb(i);
    }
    double ans = 1e18;
    for(int i : nu){
        for(int j : nv){
            ans = min(ans,dist(i,j));
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
