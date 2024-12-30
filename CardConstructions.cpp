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
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
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
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll cnt = 0;
        while(n>1){
            ll l =1,r=1e5;
            ll arest = 0;
            while(l<=r){
                ll m = l+(r-l)/2;
                ll cartas = (3*m*m+m)/2;
                if(cartas<=n){
                    arest = (3*m*m+m)/2;l=m+1;
                } else r=m-1;
            }
            n-=arest;cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
