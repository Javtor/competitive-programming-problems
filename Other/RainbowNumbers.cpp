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

ll m = 998244353;

ll dp[100005][10][2][2];

string number;

ll go(int i, int last, int limit, int trail){
    if(i==SZ(number)) return 1;
    ll &r = dp[i][last][limit][trail];
    if(r != -1) return r;
    r = 0;
    fore(dig,0,10){
        if(last == dig && !(trail && dig==0)) continue;
        if(limit && dig>(number[i]-'0')) continue;
        r = (r+go(i+1,dig,limit && dig==(number[i]-'0'),trail&&dig==0))%m;
    }
    return r%m;
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
    string L,U;cin>>L>>U;
    number = U;
    mset(dp,-1);
    ll a1 = go(0,0,1,1)%m;

    number = L;
    mset(dp,-1);
    ll a2 = go(0,0,1,1)%m;

    int Les = 1;
    fore(i,0,SZ(L)-1){
        Les&=L[i]!=L[i+1];
    }
    ll ans = ((a1-a2+Les)%m+m)%m;
    cout<<ans<<endl;
    return 0;
}
