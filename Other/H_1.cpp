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
#define MAXN 2005

// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}


void solve(){
    int N;cin>>N;
    vector<vi> grid (3, vi(N));
    fore(i,0,N)cin>>grid[0][i];
    fore(i,0,N)cin>>grid[1][i];
    fore(i,0,N)cin>>grid[2][i];
    fore(i,0,N){
        int fs = grid[0][i];
        if(fs<0)fs=-fs-1;
        else fs= neg(fs-1);
        int sn = grid[1][i];
        if(sn<0)sn=-sn-1;
        else sn=neg(sn-1);
        int tr = grid[2][i];
        if(tr<0)tr=-tr-1;
        else tr=neg(tr-1);
        addor(fs,sn);addor(fs,tr);addor(sn,tr);
    }
    if(satisf(N))cout<<"YES\n";else cout<<"NO\n";
    fore(i,0,n)g[i].clear();
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
