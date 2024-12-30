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
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

typedef vector<vector<ll>> Mat;

Mat rotateMat(Mat mat){
    ll n = SZ(mat);
    ll m = SZ(mat[0]);
    Mat nueva(m);
    fore(i,0,m)fore(j,0,n){
        nueva[i].pb(0);
    }
    fore(i,0,n)fore(j,0,m){
        nueva[j][n-1-i] = mat[i][j];
    }
    return nueva;
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
    ll n,m,q;cin>>n>>m>>q;
    Mat orig(n);
    fore(i,0,n)fore(j,0,m){
        ll a;cin>>a;
        orig[i].pb(a);
    }
    vector<Mat> rots;
    rots.pb(orig);
    fore(i,1,4){
        rots.pb(rotateMat(rots[i-1]));
    }

    vector<Mat> alturas;
    fore(k,0,4){
        Mat nxt = rots[k];
        Mat nueva(SZ(nxt));
        fore(i,0,SZ(nxt))fore(j,0,SZ(nxt[0])){
            nueva[i].pb(0);
            if(nxt[i][j]){
                if(i)nueva[i][j]+=nueva[i-1][j];
                nueva[i][j]++;
            }
        }
        alturas.pb(nueva);
    }
    while(q--){
        ll op,x,y;cin>>op>>x>>y;x--;y--;
        if(op==1){
            fore(k,0,4){
                n = SZ(rots[k]);
                m = SZ(rots[k][0]);
                Mat nxt = rots[k];
                Mat nueva = alturas[k];
                nxt[x][y] = 1-nxt[x][y];
                fore(i,x,n){
                    nueva[i][y]=0;
                    if(nxt[i][y]){
                        if(i)nueva[i][y]+=nueva[i-1][y];
                        nueva[i][y]++;
                    }
                }
                rots[k]=nxt;
                alturas[k]=nueva;
                ll tmp = y;
                y = n-1-x;
                x= tmp;
            }
        } else{
            ll ar = 0;
            fore(k,0,4){
                n = SZ(rots[k]);
                m = SZ(rots[k][0]);
                Mat nxt = alturas[k];
                ll izq = y, der = y;                
                ll alt = nxt[x][y];
                while(izq>=0&&der<m&&nxt[x][izq]+nxt[x][der]>0){
                    alt = min(alt,nxt[x][izq]);
                    alt = min(alt,nxt[x][der]);
                    ar = max(ar,alt*(der-izq+1));
                    if(izq==0&&der==m-1){
                        break;
                    } else if(izq==0) der++;
                    else if(der==m-1) izq--;
                    else if(nxt[x][der]>nxt[x][izq])der++;
                    else izq--;
                }
                
                ll tmp = y;
                y = n-1-x;
                x= tmp;
            }
            cout<<ar<<endl;
        }
        
    }
    return 0;
}
