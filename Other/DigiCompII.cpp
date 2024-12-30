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
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MAXN = 5E5+15;

vector<int> g[MAXN];int n;
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
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
    ll m; cin>>m>>n;n++;
    bool st[MAXN]; //R=1
    fore(i,1,n){
        char s;cin>>s;st[i]=s=='R';
        int l;cin>>l;g[i].pb(l);
        int r;cin>>r;g[i].pb(r);
    }
    vi balls(n);
    balls[1]=m;
    vector<int> t = tsort();
    fore(i,0,n){
        int u = t[i];
        if(u==0 ) continue;
        if(balls[u]% 2==0){
            balls[g[u][0]]+=balls[u]/2;
            balls[g[u][1]]+=balls[u]/2;
        } else{
            balls[g[u][1-st[u]]]+=balls[u]/2;
            balls[g[u][st[u]]]+=balls[u]/2+1;

            st[u]=1-st[u];
        }
    }
    fore(i,1,n){
        cout<<(st[i]?'R':'L');
    }
    return 0;
}
