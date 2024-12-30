#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int n,t;
const int MAXN = 1e3+1;
int q[MAXN], x[MAXN];
// pair<int,int> to[250001];
vector<int> ps;
int dp[MAXN][251][251];
const ll mod = 1e9+7;


int main() {FIN;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("kebab.in", "r", stdin);
    freopen("kebab.out", "w", stdout);
#define endl '\n'
#endif
    cin>>n>>t;
    fore(i,0,n) cin>>q[i]>>x[i];
    ps.pb(q[0]);
    fore(i,1,n){
        ps.pb(ps.back()+q[i]);
    }
    // fore(i,0,ps.back()+1){
    //     int dest = i+t+1;
    //     int pos = lower_bound(ALL(ps), dest)-ps.begin();
    //     if(pos==n){ to[i] = {n,0}; continue;}
    //     dest -= (pos-1>=0?ps[pos-1]:0);
    //     if(dest == q[pos]){ pos++; dest = 0;}
    //     to[i] = {pos,dest};
    // }
    memset(dp,-1,sizeof(dp));
    fore(i,0,251)fore(j,0,251)dp[1][i][j]=1;

    for(int pos=n;pos>=0;pos--){
        for(int ing = 250;ing>=0;ing--){
            for(int d = 250;d>=0;d--){
                if(pos == n) {dp[pos][ing][d] = 1;continue;}
                ll r = dp[pos][ing][d];
                r = 0;
                int real = ing+(pos-1>=0?ps[pos-1]:0);
    int newpos, newing;
    int dest = real+t+1;
    int poss = lower_bound(ALL(ps), dest)-ps.begin();
    if(poss==n){ newpos=n; newing=0;}
    else{
        dest -= (poss-1>=0?ps[poss-1]:0);
        if(dest == q[poss]){ poss++; dest = 0;}
        newpos=poss; newing=dest;
    }
                if(newpos != pos){
                    if(q[pos]-(d+1) >= x[pos]) r = (r+dp[newpos][newing][0])%mod;
                }else r = (r+dp[newpos][newing][d+1])%mod;
                if(ing+1 == q[pos]){
                    if(q[pos]-d >= x[pos]) r = (r+dp[pos+1][0][0])%mod;
                }else r = (r+dp[pos][ing+1][d])%mod;
                dp[pos][ing][d] = (int)(r);
            }
        }
    }
    cout<<dp[0][0][0]<<"\n";
    int asd = 4;
    return 0;
}
