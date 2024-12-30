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

bool isOk(const string& s){
    int n = SZ(s);
    vector<int> sq(n);
    vector<int> acc(n);
    fore(j,0,n){
        bool ok = 1;
        fore(k,1,(n-j)/2 +1){
            bool curOk = s.substr(j,k) != s.substr(j+k,k);
            ok &=curOk;
        }
        sq[j]=ok;
    }
    acc[0]=sq[0];
    fore(j,1,n)acc[j]=sq[j]+acc[j-1];
    bool ok=1;
    fore(j,0,n){
        bool curOk = 2*acc[j]>=j+1;
        ok&=curOk;
    }
    return ok;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("free.in", "r", stdin);
    freopen("free.out", "w", stdout);
#define endl '\n'
#endif

    int n;cin>>n;
    vector<string>ans = {"0","1"};
    
    for(int i = 1; i+1<=n;i++){
        vector<string> cans;
        fore(j,0,SZ(ans)){
            if(isOk(ans[j]+"0")) cans.pb(ans[j]+"0");
            if(isOk(ans[j]+"1")) cans.pb(ans[j]+"1");
        }
        ans = cans;
    }
    cout<<SZ(ans)<<endl;
    sort(ALL(ans));
    for(auto s:ans)cout<<s<<endl;
    return 0;
}
