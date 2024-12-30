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
    ll n,k,q;cin>>n>>k>>q;
    vi a(k+1), b(k+1);
    fore(i,0,k){
        ll ai;cin>>ai;
        a[i+1]=ai;
    }
    fore(i,0,k){
        ll bi;cin>>bi;
        b[i+1]=bi;
    }
    // fore(i,0,n)cin>>b[i+1];
    while(q--){
        ll d;cin>>d;
        int k = upper_bound(a.begin(), a.end(), d) - a.begin();
        int l = k-1;
        ll dif = d-a[l];
        if(dif==0){
            cout<<b[l]<<' ';
            continue;
        }
        ll num = (dif * (b[l+1]-b[l]));
        ll den = (a[l+1]-a[l]);
        cout<<(b[l]+ (num/den))<<' ';
    }
    cout<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
