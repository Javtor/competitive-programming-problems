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
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI acos(-1)
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MAXN = 5E5+15;

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
		int x=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;}
		while(x!=u);

		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}
vector<int> g2[MAXN];
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g2[i].size())d[g2[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g2[x].size()){
			d[g2[x][i]]--;
			if(!d[g2[x][i]])q.push(-g2[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
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
    int cs=1,t;cin>>t;
    while(t--){
        fore(i,0,MAXN){g[i].clear();g2[i].clear();}
        cin>>n;
        fore(i,0,n){
            int u,v;cin>>u>>v;
            g[--u].pb(--v);
        }
        scc();
        vi sz(n,0);
        
        vi trad(qcmp,0);
        fore(i,0,n){
            sz[cmp[i]]++;
            if(!trad[cmp[i]])trad[cmp[i]]=i+1;
            fore(j,0,SZ(g[i]))if(cmp[i]!=cmp[g[i][j]])g2[cmp[i]].pb(cmp[g[i][j]]);
        }
        n=qcmp;
        vi dp(n);
        vector<int> ts = tsort();
        ll ans=0, indans=0;
        for(int k = qcmp-1;k>=0;k--){
            int i = ts[k];
            dp[i]=sz[i];
            if(SZ(g2[i]))dp[i]+=dp[g2[i][0]];
            if(dp[i]>=ans){ans=dp[i];indans=i;}
        }

        cout<<"Case "<<(cs++)<<": "<<trad[indans]<<endl;
    }
    return 0;
}
