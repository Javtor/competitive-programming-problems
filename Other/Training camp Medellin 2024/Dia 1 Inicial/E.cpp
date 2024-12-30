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
    string s;cin>>s;
    int e = 0, ne = 0;
    fore(i,0,n){
        if(s[i]=='8') e++;
        else ne++;
    }
    int ans = 0;
    bool can = true;
    while(can){
        if(e && (e-1+ne >=10)){
            ans++;
            e--;
            if(ne>=10) ne-=10;
            else{
                e-=(10-ne);
                ne=0;
            }
        } else{
            can = false;
        }
    }
    cout<<ans;
}

int main(){FIN;
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
