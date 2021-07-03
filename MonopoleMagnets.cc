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

struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
};

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
    UnionFind uf(n*m+1);
    bool blk[n][m];
    fore(i,0,n)fore(j,0,m){
        char c;cin>>c;blk[i][j]=c=='#';
        if(!blk[i][j])
            uf.join(m*i+j,n*m);
    }
    int emptyr = 0,emptyc=0;
    //TODO: todas al menos un south
    fore(i,0,n){
        int fir = -1, las = 0;
        fore(j,0,m)if(blk[i][j]){
            if(fir==-1)fir=j;
            las=j;
        }
        if(fir==-1){
            emptyr++;continue;
        }
        fore(j,fir,las+1)uf.join(m*i+j,m*i+fir);
    }

    fore(j,0,m){
        int fir = -1, las = 0;
        fore(i,0,n)if(blk[i][j]){
            if(fir==-1)fir=i;
            las=i;
        }
        if(fir==-1){
            emptyc++;continue;
        }
        fore(i,fir,las+1)
            uf.join(m*i+j,m*fir+j);
    }

    set<int> comps;
    fore(i,0,n*m){
        if(uf.find(i)!=uf.find(n*m))
            comps.insert(uf.find(i));
    }
    int ans = comps.size();
    bool pos = 1;
    fore(i,0,n)fore(j,0,m){
        pos = pos && ((blk[i][j] && uf.find(m*i+j)!=uf.find(n*m))
        || (!blk[i][j] && uf.find(m*i+j)==uf.find(n*m)));
    }
    if(emptyc ||emptyr) pos = emptyc && emptyr;
    
    if(!pos){
        cout<<-1;return 0;
    }
    cout<<ans;
    return 0;
}
