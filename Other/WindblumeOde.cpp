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

bool comp(int n){
    fore(i,2,n-1){
        if(n%i==0)return true;
    }
    return false;
}

void solve(){
    int n;cin>>n;
    int a[n];
    fore(i,0,n)cin>>a[i];
    int sum = 0;
    int odi = -1;
    fore(i,0,n){
        sum+=a[i];
        if(a[i]&1)odi=i;
    }
    cout<<(!comp(sum)?n-1:n)<<endl;
    fore(i,0,n){
        if(!(i==odi && !comp(sum))) cout<<(i+1)<<' ';
    }
    cout<<endl;
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
