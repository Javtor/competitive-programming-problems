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
    vi next(n,-1);
    fore(i,0,n){
        cout<<"? ";
        fore(j,0,n){
            if(i==j)cout<<"2 ";
            else cout<<"1 ";
        }
        cout<<endl;
        cout.flush();
        int k;cin>>k;k--;
        if(k!=i)next[i]=k;
    }
    fore(i,0,n){
        cout<<"? ";
        fore(j,0,n){
            if(i==j)cout<<"1 ";
            else cout<<"2 ";
        }
        cout<<endl;
        cout.flush();
        int k;cin>>k;k--;
        if(k>-1 && k!=i)next[k]=i;
    }
    set<int> s;
    fore(i,0,n)s.insert(i);
    fore(i,0,n)if(s.count(next[i]))s.erase(next[i]);
    vi res(n);
    int primer = *(s.begin());
    fore(i,1,n+1){
        res[primer] = i;
        primer = next[primer];
    }
    cout<<"! ";
    fore(i,0,n)cout<<res[i]<<' ';
    cout.flush();
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
