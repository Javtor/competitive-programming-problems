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
    ll n;cin>>n;
    ll ans = 1;
    while(n>3){
        n /=4;
        ans = ans <<1;
    }

    cout<<ans<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
