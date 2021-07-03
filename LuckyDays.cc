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
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    ll la,ra,ta;cin>>la>>ra>>ta;
    ll lb,rb,tb;cin>>lb>>rb>>tb;
    ll g = __gcd(ta,tb);
    if(la>lb){
        swap(la,lb);
        swap(ra,rb);
    }
    ll cua = (lb-la)/g;
    ll ans = 0;
    fore(i,-2,3){
        ll tl = la+g*(cua+i);
        ll tr = ra+g*(cua+i);
        ans = max(ans,min(rb,tr)-max(lb,tl)+1);
    }
    cout<<ans;
    return 0;
}
