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
    vector<string> s(n);
    fore(i,0,n){
        fore(j,0,5){char c;cin>>c;s[i]+=c;}
    }

    fore(d1,0,5)fore(d2,d1+1,5){
        bool pos = 1;
        int cd1 =0, cd2 = 0;
        fore(i,0,n){
            pos = pos && (s[i][d1]=='1' || s[i][d2]=='1');
            cd1+=s[i][d1]=='1';
            cd2+= s[i][d2]=='1';
        }
        if(pos && cd1 && cd2){
            cout<<"YES"<<endl;return;
        }
    }

    cout<<"NO"<<endl;
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
    cin>>t;
    while(t--)solve();
    return 0;
}
