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
    int q;
    cin >> q;
    int cnt = 0;
    map<string, int> mp;
    vector<string> res;
    fore(i, 0, q)
    {
        string ins, tm;
        cin >> ins >> tm;
        if(cnt>=10) continue;
        if (ins == "SCH" || mp[ins] >= 4 || (ins != "MSU" && mp[ins] >= 2))
        {
            continue;
        }
        res.pb(ins+" "+tm);
        cnt++;
        mp[ins]++;
    }
    cout<<cnt<<endl;
    assert(cnt==res.size());
    fore(i,0,cnt){
        cout<<res[i]<<endl;
    }
    return 0;
}
