#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a, b) memset(a, b, sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    ll F,A,B,C;cin>>F>>A>>B>>C;
    ll m,n;cin>>m>>n;
    map<ll,ll> mp;
    fore(i,0,m)fore(i,0,n){
        ll z;cin>>z;
        mp[z]++;
    }
    vector<pair<ll,ll>> stocks;
    for(auto pr : mp){
        stocks.pb({pr.snd,pr.fst});
    }
    sort(ALL(stocks));
    vector<pair<ll,ll>> days;
    days.pb({F,0});
    fore(i,1,SZ(stocks)){
        days.pb({((A*days[i-1].fst+B)%C)+1, i});
    }
    sort(ALL(days));
    vector<ll> sol(stocks.size());
    fore(i,0,stocks.size()){
        sol[days[i].snd] = stocks[i].snd;
    }
    cout<<SZ(sol)<<endl;
    fore(i,0,SZ(sol)){
        cout<<sol[i]<<' ';
    }
    int asd = 4;
    return 0;
}
