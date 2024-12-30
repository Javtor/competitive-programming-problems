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
    if(n==1)cout<<1;
    else if(n==4)cout<<"3 1 4 2";
    else if(n<5)cout<<"NO SOLUTION";
    else{
    string l = "", r = "";
    fore(i,1,n+1){
        if(i&1){
            l+=to_string(i)+' ';
        } else{
            r+=to_string(i)+' ';
        }
    }
    cout<<l<<r;
    }
}

int main(){FIN;
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
