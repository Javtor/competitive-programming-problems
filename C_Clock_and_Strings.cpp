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
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    int cnt = 0;
    fore(i,a,b){
        if(i==c || i==d) cnt++;
    }
    if (cnt&1)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
