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


int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    ll r,c,s;cin>>r>>c>>s;
    vector<vector<ll>> mat(min(r,c),vector<ll>(max(r,c)));
    if(r<=c){
        fore(i,0,r)fore(j,0,c)cin>>mat[i][j];
    } else{
        swap(r,c);
        fore(j,0,c)fore(i,0,r)cin>>mat[i][j];
    }
    vector<vector<ll>> par(r+1,vector<ll>(c));
    fore(i,0,r)fore(j,0,c)par[i+1][j] = par[i][j]+mat[i][j];
    ll ans = 1e18;
    fore(h,1,r+1){
        for(int row =0; row+h <= r; row++){
            vector<ll> parc(c);
            fore(i,0,c) parc[i] = par[row+h][i] - par[row][i];
            ll sum = 0;
            vector<pair<ll,ll>> deltas;
            fore(col,0,c){
                sum += parc[col];
                ll delta = parc[col]-sum;
                //Parcial desde i hasta col es sum+deltas[i].snd

                while(SZ(deltas) && deltas.back().snd <= delta){
                    deltas.pop_back();
                }
                deltas.pb({col,delta});

                if(sum+deltas[0].snd < s) continue;

                int l = 0, r = SZ(deltas)-1;
                int cur = 0;
                while(l<=r){
                    int m = l + (r-l)/2;
                    ll check = sum+deltas[m].snd;
                    if(check >= s){
                        cur = m;
                        l = m+1;
                    } else{
                        r = m-1;
                    }
                }
                ans = min(ans, (ll)h*(ll)(col - deltas[cur].first +1));

            }
        }
    }
    if(ans == 1e18) ans = -1;
    cout<<ans<<endl;
    return 0;
}
