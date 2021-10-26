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

void solve(){
    int n;cin>>n;
    vi a(n);
    fore(i,0,n)cin>>a[i];
    int m;cin>>m;
    while(m--){
        int x,y;cin>>x>>y;
        x--;
        if(x){
            a[x-1]+=y-1;
        }
        if(x < n-1){
            a[x+1]+=a[x]-y;
        }
        a[x]=0;
    }
    fore(i,0,n)cout<<a[i]<<endl;
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
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
