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
    string s;cin>>s;
    int n = SZ(s);
    int q;cin>>q;
    vi podd(n);
    vi peven(n);
    fore(i,0,n){
        if(s[i]=='['||s[i]==']'){
            if(i%2)podd[i]=1;
            else peven[i]=1;
        }
    }
    fore(i,1,n){podd[i]+=podd[i-1];peven[i]+=peven[i-1];}
    while(q--){
        int l,r;cin>>l>>r;l--;r--;
        int sodd = podd[r], seven = peven[r];
        if(l){
            sodd-=podd[l-1];
            seven-=peven[l-1];
        }
        cout<<abs(sodd-seven)<<endl;
    }
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
