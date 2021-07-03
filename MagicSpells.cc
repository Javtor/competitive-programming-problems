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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    vector<vector<int>> idx(26);
    string s;cin>>s;
    fore(i,0,SZ(s)){
        int ind = s[i]-'a';
        idx[ind].pb(i);
    }
    int n;cin>>n;
    fore(i,0,n){
        string a;cin>>a;
        string ans = "";
        int curInd = -1;
        fore(j,0,SZ(a)){
            int car = a[j]-'a';
            if(upper_bound(ALL(idx[car]),curInd) != idx[car].end()){
                curInd = *upper_bound(ALL(idx[car]),curInd);
                ans+=a[j];
            } else{
                break;
            }
        }
        if(!SZ(ans)) ans = "IMPOSSIBLE";
        cout<<ans<<endl;
    }
    return 0;
}
