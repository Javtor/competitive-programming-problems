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
 
int main() {FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n,m; cin>>n>>m;
    vector<ll> a(n), b(m);
    ll mx = 0, f = -1;
    int mxind = 0;
    fore(i,0,n){ cin>>a[i];
        if(a[i] > mx){
            mx = a[i]; f = 0;
            mxind = i;
        }
    }
    fore(i,0,m){ cin>>b[i];
        if(b[i] > mx){
            mx = b[i]; f = 1;
            mxind = i;
        }
    }
    ll ans = 0, sum = 0;
    if(f == 0){
        fore(i,0,m) sum += b[i];
        ans += sum;
        fore(i,0,n){
            if(i==mxind)continue;
            ans+=min(a[i],sum);
        }
    }else{
        fore(i,0,n) sum += a[i];
        ans += sum;
        fore(i,0,m){
            if(i==mxind)continue;
            ans+=min(b[i],sum);
        }
    }
    cout<<ans<<"\n";
    return 0;
}