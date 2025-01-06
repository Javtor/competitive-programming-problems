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

ll inf = 1e9;

ll max_sum(vi &a){
    ll ans=0, cur=0;
    fore(i,0,SZ(a)){
        cur = max(0LL,cur+a[i]);
        ans = max(ans,cur);
    }
    return ans;
}

void solve(){
    int n;cin>>n;
    vi a(n);
    fore(i,0,n)cin>>a[i];
    int idx = -1, val = 0;
    fore(i,0,n)if(a[i]!=1 && a[i] != -1){idx=i;val=a[i];}
    ll mi=0,ma=0;
    // find max
    // dont include the strange el
    if(idx != -1)a[idx]=-inf;
    ma = max_sum(a);
    //find min
    fore(i,0,n)a[i]*=-1;
    if(idx != -1)a[idx]=-inf;
    mi = -max_sum(a);
    fore(i,0,n)a[i]*=-1;

    set<ll> ans;
    // cout<<"mi"<<mi<<"ma"<<ma<<endl;
    fore(i,mi,ma+1)ans.insert(i);
    // cout<<"ma"<<ma<<endl;
    // cout<<"mi"<<mi<<endl;

    if(idx != -1){
        a[idx]=inf;
        ma = max_sum(a)-inf+val;
        // cout<<"ma"<<ma<<endl;
        fore(i,0,n)a[i]*=-1;
        a[idx]=inf;
        mi = -(max_sum(a)-inf) + val;
        // cout<<"mi"<<mi<<endl;
        fore(i,mi,ma+1)ans.insert(i);
    }

    cout<<SZ(ans)<<endl;
    for(ll num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
