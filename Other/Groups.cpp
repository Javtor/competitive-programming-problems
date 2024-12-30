#ifndef LOCAL
#pragma GCC optimize(2)
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

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
        int ca =0, cb = 0, c2=0;
        fore(i,0,n){
            bool pa = s[i][d1]=='1';
            bool pb =  s[i][d2]=='1';
            if(pa &&!pb)ca++;
            else if(!pa && pb)cb++;
            else if(pa)c2++;
        }
        if(ca<=n/2&&cb<=n/2&&ca+cb+c2==n){
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
