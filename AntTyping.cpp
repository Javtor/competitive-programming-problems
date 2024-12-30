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
    int pairs[9][9];
    mset(pairs,0);
    fore(i,0,SZ(s)-1){
        int c1 = s[i]-'1', c2 = s[i+1]-'1';
        pairs[c1][c2]++;
    }
    int digitos[] = {0,1,2,3,4,5,6,7,8};
    ll ans = 1e18;
    do{
        int ind[9];
        ll cur = 0;
        fore(i,0,9){
            ind[digitos[i]] = i;
        }
        cur += ind[s[0]-'1'];
        fore(i,0,9)fore(j,0,9){
            cur += pairs[i][j]*abs(ind[i]-ind[j]);
        }
        ans = min(ans,cur);
    } while(next_permutation(digitos,digitos+9));
    ans+=SZ(s);
    cout<<ans<<endl;
    return 0;
}
