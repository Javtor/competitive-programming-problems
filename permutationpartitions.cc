#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    vector<pair<ll,int>> v;
    fore(i,0,n){
        ll a; cin>>a;
        v.pb({-a,i});
    }
    sort(all(v));
    vector<int> ind;
    ll sum = 0;
    ll perm = 1;
    fore(i,0,k){
        sum+= -v[i].fst;
        ind.pb(v[i].snd);
    }
    sort(all(ind));
    fore(i,0,k-1){
        perm *= ind[i+1]-ind[i];
        perm %= 998244353;
    }
    cout << sum << " " <<perm <<"\n";
    return 0;
}
