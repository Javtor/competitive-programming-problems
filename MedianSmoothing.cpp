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
    int n;cin>>n;
    int a[n];
    fore(i,0,n)cin>>a[i];
    int res = 0;
    int sigo = 0;
    int l=0,r=0;
    fore(i,1,n){
        if(i != n-1 && a[i]!= a[i-1] && a[i] != a[i+1]){
            if(!sigo){
                sigo = 1;
                l = i;
                r = i;
                res = max(res, r-l+1);
            } else{
                r = i;
                res = max(res, r-l+1);
            }
        } else{
            if(sigo){
                sigo = 0;
                fore(j,l,l+(r-l+1)/2){
                    a[j] = a[l-1];
                }
                fore(j,l+(r-l+1)/2,r+1){
                    a[j] = a[r+1];
                }
            }
        }
    }
    cout<<((res+1)/2)<<endl;
    fore(i,0,n)cout<<a[i]<<' ';
    return 0;
}
