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
    ll x,y,z,k;cin>>x>>y>>z>>k;
    ll mx = -1;
    fore(a,1,x+1)fore(b,1,y+1){
        ll c = k/(a*b);
        if(c>z || (a*b*c)!=k){
            continue;
        }
        mx = max(mx,(x-a+1)*(y-b+1)*(z-c+1));
    }
    if(mx==-1)mx=0;
    cout<<mx<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
