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
    int n,m;cin>>n>>m;
    vector<string> a(n);
    fore(i,0,n)cin>>a[i];
    vector<int> pos(m);
    fore(i,1,n)fore(j,1,m)if(a[i-1][j]=='X' && a[i][j-1]=='X')pos[j]++;
    fore(i,1,m)pos[i]+=pos[i-1];
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;l--;r--;
        cout<<((pos[r]-pos[l])?"NO":"YES")<<endl;
    }
}
