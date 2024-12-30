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
        int a,b,c;cin>>a>>b>>c;
        int m = max(max(a,b),c);
        int empate = (a==m)+(b==m)+(c==m)>1;
        int na = a==m && !empate?0:m-a+1;
        int nb = b==m && !empate?0:m-b+1;
        int nc = c==m && !empate?0:m-c+1;
        cout<<na<<' '<<(nb)<<' '<<(nc)<<endl;
    }
    
    return 0;
}
