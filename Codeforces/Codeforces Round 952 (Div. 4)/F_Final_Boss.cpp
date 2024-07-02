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

void solve(){
    int h,n;cin>>h>>n;
    vi dmg(n), cool(n);
    fore(i,0,n)cin>>dmg[i];
    fore(i,0,n)cin>>cool[i];
    ll l = 0;
    ll r = cool[0]*h;
    ll ans = 0;
    while(l<=r){
        bool can = false;
        ll m = l + (r-l)/2;
        ll total = 0;
        fore(i,0,n){
            ll how_many = 1+m/cool[i];
            can = can || total + dmg[i]*how_many >= h;
            if(can) break;
            total += dmg[i]*how_many;
        }
        if(can){
            ans = m+1;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout<<ans<<endl;

}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
