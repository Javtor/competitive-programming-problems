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
    vector<ii> cards;
    int n;cin>>n;
    fore(i,0,n){
        ll a,b;cin>>a>>b;
        cards.pb({-b,-a});
    }
    sort(ALL(cards));
    int cnt = 1,i=0;
    ll ans = 0;
    while(i<n&&cnt){
        cnt--;
        cnt+=(-cards[i].fst);
        ans+=(-cards[i].snd);
        i++;
    }
    cout<<ans;
    return 0;
}
