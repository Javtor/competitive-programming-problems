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

bool chk(ll x, ll y, ll r){
    return ((r*r)<=(x*x+y*y)) && ((x*x+y*y)<(r+1)*(r+1));
}

void solve(){
    ll r;cin>>r;
    ll cury = r;
    int ans = 0;
    fore(i,0,r+1){
        bool could = false;
        ll cur = cury;
        while(cur>0){
            bool cchk = chk(i,cur,r);
            if( cchk) {
                cury = cur;
                could = true;
                ans ++;
            } else{
                if (could){break;}
            }
            cur--;
        }
    }
    cout<<ans*4<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
