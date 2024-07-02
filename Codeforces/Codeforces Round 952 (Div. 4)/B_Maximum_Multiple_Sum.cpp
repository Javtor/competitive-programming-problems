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
    ll mx = 0;
    int ans = 0;
    int n;cin>>n;
    fore(x,2,n+1){
        ll sum = 0;
        ll cur = x;
        while(cur<=n){
            sum+=cur;
            cur+=x;
        }
        if(sum > mx){
            ans = x;
        }
        mx = max(mx,sum);
    }
    cout<<ans<<endl;

}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
