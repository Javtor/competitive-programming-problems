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
    string s;cin>>s;
    set<string> cmb;
    cmb.insert("RBL");
    cmb.insert("RLB");
    cmb.insert("BRL");
    cmb.insert("BLR");
    cmb.insert("LRB");
    cmb.insert("LBR");
    
    char cnt[128];
    cnt['R'] = 'S';
    cnt['B'] = 'K';
    cnt['L'] = 'H';
    string ans = "";
    fore(i,0,SZ(s)){
        if(i<=SZ(s)-3 && cmb.count(s.substr(i,3))){
            ans+='C';
            i+=2;
        } else
        {
            ans+=cnt[s[i]];
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
