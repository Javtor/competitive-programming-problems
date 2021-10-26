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

set<int> getdiv(int n){
    set<int> div;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0){
            div.insert(i);div.insert(n/i);
        }
    }
    return div;
}

void solve(){
    int n;cin>>n;
    vi a(n);
    fore(i,0,n)cin>>a[i];
    sort(ALL(a));
    int res = 0;
    fore(i,0,n){
        int cur = a[i];
        int same = 0;
        fore(j,i,n){
            if(a[j]==cur)same++;
        }
        if(same>=n/2){cout<<(-1)<<endl;return;}
        map<int,int> divs;
        fore(j,i,n){
            if(a[j]!=cur)for(int d : getdiv(a[j]-cur)) divs[d]++;
        }
        
        for(auto pp : divs) if(same+pp.snd >=n/2)res=max(res,pp.fst);       
    }
    cout<<res<<endl;
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
    int t;cin>>t;while(t--)solve();
    return 0;
}
