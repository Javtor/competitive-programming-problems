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
    string s1 = "RGB",s2="GBR",s3="BRG";
    int q;cin>>q;
    while(q--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vector<bool> o1(n),o2(n),o3(n);
        fore(i,0,n){
            o1[i]=s[i]!=s1[i%3];
            o2[i]=s[i]!=s2[i%3];
            o3[i]=s[i]!=s3[i%3];
        }
        ll ans = 1e18;
        ll a1=0,a2=0,a3=0;
        fore(i,0,k){
            a1+=o1[i];
            a2+=o2[i];
            a3+=o3[i];
        }
        ans = min(a1,min(a2,a3));
        fore(i,k,n){
            a1+=o1[i];
            a2+=o2[i];
            a3+=o3[i];

            a1-=o1[i-k];
            a2-=o2[i-k];
            a3-=o3[i-k];

            ans = min(ans,min(a1,min(a2,a3)));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
