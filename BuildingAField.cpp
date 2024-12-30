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
    vector<ll> pts(n);
    fore(i,0,n){
        cin>>pts[i];
    }
    fore(i,1,n){
        pts[i]+=pts[i-1];
    }
    ll s = pts[n-1];
    if(s%2){
        cout<<'N'<<endl;
        return 0;
    }
    int cnt = 0;
    fore(i,0,n){
        ll busco = (pts[i]+s/2)%s;
        if(busco==0)busco=s;
        ll enc = *lower_bound(pts.begin(),pts.end(),busco);
        if(enc == busco){
            cnt++;
        }
    }
    if(cnt>=4){
        cout<<'Y'<<endl;
    } else{
        cout<<'N'<<endl;
    }
    
    return 0;
}
