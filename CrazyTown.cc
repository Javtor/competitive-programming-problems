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
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));
ll sign(ll a, ll b, ll c, ll x, ll y){
	ll numb = a*x+b*y+c;
	return numb/abs(numb);
}
int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	int n;cin>>n;
	int cnt=0;	
	while(n--){
		ll a,b,c;cin>>a>>b>>c;
		if(sign(a,b,c,x1,y1)!=sign(a,b,c,x2,y2))cnt++;
	}

    cout<<cnt;
    return 0;
}
