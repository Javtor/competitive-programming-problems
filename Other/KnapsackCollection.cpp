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
     ll n,s,t; cin>>n>>s>>t;
    map<int,int> mp;
    fore(i,0,n){
        int a; cin>>a;
        mp[a]++;
    }
    set<pair<int,int>> st;
    set<int> p;
    for(auto v: mp){        
        st.insert({v.fst,v.snd});
        p.insert(v.fst);
    }
    ll ans = 0, mn = 1e18, mx = -1;
    map<int,ll> anss;
    for(auto pos: p){
        int i = pos;
        ll auxs = 0;
        while(!st.empty()){
            auto it = st.lower_bound({i,0});
            if(it == st.end()) it = st.begin();
            pair<int,int> rem = *it;
            ll ini = rem.fst-i;
            if(ini < 0) 
                ini = s-i+rem.fst;
            ll taken = ini + t;
            auxs += taken;
            int sl = rem.fst, ne = rem.snd-1;
            st.erase(rem);
            if(ne > 0) st.insert({sl,ne});
            i += (taken%s); i%= s;
        }
        // cout<<pos<<" "<<auxs<<"\n";
        mn = min(mn,auxs);
        mx = max(mx,auxs);
        ans += auxs;
        anss[pos]=auxs;
        for(auto v: mp){
            st.insert({v.fst,v.snd});
        }
    }
    fore(i,0,s){
        auto it = p.lower_bound(i);
        if(it == p.end()) it = p.begin();
        if(*it==i) continue;
        int male = *it;
        ll dis = male-i;
        if(dis < 0) 
            dis = s-i+male;
        ll asumar=dis+anss[male];
        mx = max(mx,asumar);
        ans+=asumar;
    }
    ll gcd = __gcd(ans,s);
    cout<<mn<<"\n"<<mx<<"\n"<<ans/gcd<<'/'<<s/gcd<<"\n";

    return 0;
}
