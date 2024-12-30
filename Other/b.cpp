#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define EPS 1e-9
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

string a[30];
int h,w;
double r;
ll s;
int st, en;
vector<pair<pair<int,int>,int>> v;
const int MAXS = 6000;
const int MAXN = 1000;
vector<pair<int,double>> g[MAXN*MAXS+15];

double eucl(double x0, double y0, double x1, double y1){
    return (x1-x0)*(x1-x0)+(y1-y0)*(y1-y0) ;
}

double dist[MAXN*MAXS+15];
void dijkstra(int x){
    fore(i,0,MAXN*MAXS+15){
        dist[i]=-1;
    }
	priority_queue<pair<double,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;double c=-q.top().fst;q.pop();
		if(abs(dist[x]-c) > EPS)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; double c=g[x][i].snd;
			if(dist[y]< -EPS||dist[x]+c - dist[y]< -EPS)
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

int main() {FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin>>h>>w>>r>>s;
    double rr = r*r;
    fore(i,0,h) cin>>a[i];
    st = -1, en = -1;
    fore(i,0,h){
        fore(j,0,w){
            if(a[i][j] == '.') continue;
            int num = a[i][j] - '0';
            v.pb({{i,j},num});
            if(st == -1 || (v[st].fst.fst < v.back().fst.fst)) st = SZ(v)-1;
            if(en == -1 || (v[en].fst.fst > v.back().fst.fst)) en = SZ(v)-1;
        }
    }
    int m = SZ(v);
    fore(i,0,m){
        fore(j,i+1,m){
            if(r*r-eucl(v[i].fst.fst,v[i].fst.snd,v[j].fst.fst,v[j].fst.snd) >= 0){
                ll si = v[i].snd, sj = v[j].snd;
                fore(stam,0,MAXS){
                    if(stam-si >=0)
                        g[i*MAXS+stam].pb({j*MAXS+stam-si, sqrt(eucl(v[i].fst.fst,v[i].fst.snd,v[j].fst.fst,v[j].fst.snd))});
                    if(stam-sj>=0)
                        g[j*MAXS+stam].pb({i*MAXS+stam-sj, sqrt(eucl(v[i].fst.fst,v[i].fst.snd,v[j].fst.fst,v[j].fst.snd))});
                }
                g[i].pb({j,v[j].snd}); g[j].pb({i,v[i].snd});
            }
        }
    }
    if(v[st].snd > s){ cout<<"impossible\n"; return 0;}
    int realst = MAXN*MAXS+14;
    int realen = MAXN*MAXS+13;
    g[realst].pb({st*MAXS+min((ll)MAXS-1,s), 0});
    fore(stam,0,MAXS){
        if(stam-v[en].snd>=0)
        g[en*MAXS+stam].pb({realen,0});
    }
    dijkstra(realst);
    if(dist[realen] == -1)cout<<"impossible\n";
    // cout<<dist[realen];
    else cout<<fixed<<setprecision(15)<<dist[realen]<<"\n";
    return 0;
}

