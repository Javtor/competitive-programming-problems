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
struct objects{
    int weight,value;
};

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
int n,w;
   cin>>n>>w;
   objects object[n];
   int totalvalue=0;
   for(int i=0;i<n;i++){
       cin>>object[i].weight>>object[i].value;
       totalvalue+=object[i].value;
   }
   ll dp[n+1][totalvalue+1];
   dp[0][0]=0;
   int ans=0;
   for(int i=1;i<=totalvalue;i++){
       dp[0][i]=1e18;
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<=totalvalue;j++){
           if(j>=object[i].value){
                dp[i+1][j]=min(dp[i][j], dp[i][j-object[i].value]+object[i].weight);
           }
           else{
               dp[i+1][j]=dp[i][j];
           }
           if(dp[i+1][j]<=w){
               ans=max(ans,j);
           }
       }
   }
   cout<<ans;
    return 0;
}
