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
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

bool cmp(const pair<string,int> &p1, const pair<string,int> &p2){
    
    return make_pair(p1.snd,p1.fst)<make_pair(p2.snd,p1.fst);
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
    map<string,int> mp;
    int n;cin>>n;
    int N = n;
    while(n--){
        string s;cin>>s;
        mp[s]++;
    }
    vector<pair<string,int>> v;
    for(auto it : mp){
        v.pb(it);
    }
    sort(ALL(v),cmp);
    reverse(ALL(v));
    string st = v[0].fst;
    int times = v[0].snd;
    if(times <= N/2)cout<<"NONE";
    else cout<<st;
    return 0;
}
