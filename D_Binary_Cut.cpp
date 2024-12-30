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
    int blocks=1;
    char cur = s[0];
    bool has01 = false;
    fore(i,1,SZ(s)){
        if(s[i]=='1' && s[i-1]=='0'){
            has01=true;
        }
        if(s[i] != cur){
            blocks++;
            cur=s[i];
        }
    }
    cout<<(blocks-has01)<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
