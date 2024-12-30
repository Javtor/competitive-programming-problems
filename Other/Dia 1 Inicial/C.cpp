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
    int n,m;ll k;cin>>n>>m>>k;
    vi a(n), b(m);
    fore(i,0,n) cin>>a[i];
    fore(i,0,m) cin>>b[i];
    sort(ALL(a));sort(ALL(b));
    int i=0,j=0,ans=0;
    while(i<n&&j<m){
        if(abs(a[i]-b[j])<=k){
            i++;j++;ans++;
        } else{
            if(a[i]-b[j]>k){
                j++;
            } else {
                i++;
            }
        }
    }
    cout<<ans;
}

int main(){FIN;
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
