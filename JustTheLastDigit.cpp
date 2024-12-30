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
    ll n;cin>>n;
    vector<vector<int>> a(n,vector<int>(n)), ans(n,vector<int>(n));
    fore(i,0,n)fore(j,0,n){char aij;cin>>aij;a[i][j]=aij-'0';}
    for(int i = n-2; i>=0; i--){
        fore(j,i+1,n){
            ll sum = 0;
            fore(k,i+1,j) sum = (sum+ans[i][k]*a[k][j])%10;
            if(sum!=a[i][j])ans[i][j]=1;
        }
    }
    fore(i,0,n){
        fore(j,0,n)cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}
