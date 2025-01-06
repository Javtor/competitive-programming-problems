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
    int n,d;cin>>n>>d;
    vi digits;
    digits.pb(1);
    if (d%3==0 || n>=3) digits.pb(3);
    if (d==5) digits.pb(5);
    if (d == 7 || n>2) digits.pb(7);
    if (d==9 || n >= 6 || (d%3==0 && n>=3))digits.pb(9);
    fore(i,0,SZ(digits)) cout<<digits[i]<<' ';
    cout<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
