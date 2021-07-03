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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("minima.in", "r", stdin);
    freopen("minima.out", "w", stdout);
#define endl '\n'
#endif
    vector<int> a,b;
    set<pair<int,int>> L;
    map<int,int> pos;
    int n;cin>>n;
    fore(i,0,n){
        int val;cin>>val;
        a.pb(val);
        L.insert({i+1,i+1});
        pos[i+1] = i;
    }
    int front = 0;
    fore(i,0,n){
        int posAct = pos[a[i]]-front;

        auto act = L.erase({pos[a[i]],a[i]});
        front--;
        L.insert({front,a[i]});
        pos[a[i]] = front;

    }

    return 0;
}
