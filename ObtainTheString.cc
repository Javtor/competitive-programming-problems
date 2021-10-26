#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int t;cin>>t;
    while(t--){
        vector<int> ind[128];
        string s,t;cin>>s>>t;
        fore(i,0,SZ(s)){
            ind[s[i]].pb(i);
        }
        int ans = 0;
        int ac = 1e9;
        fore(i,0,SZ(t)){
            if(ind[t[i]].empty()){
                ans = -1;break;
            }
            int next = upper_bound(ALL(ind[t[i]]),ac)-ind[t[i]].begin();
            
            if(next==SZ(ind[t[i]])){ac=ind[t[i]][0];ans++;}
            else ac=ind[t[i]][next];
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
