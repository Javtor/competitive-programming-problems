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
    int n;cin>>n;
    vi a(n);
    fore(i,0,n)cin>>a[i];
    int ans = 0;
    ll csum = 0;
    ll cmx = -1;
    fore(i,0,n){
        ll cur = a[i];
        if(cur > cmx){
            if (cmx != -1)
                csum += cmx;
            cmx = cur;
        } else{
            csum+=cur;
        }

        if(csum == cmx){ans++;}
    }
    cout<<ans<<'\n';
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
