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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    int n, c; cin>>n>>c;

    vector<vector<ll>> dp(2,vector<ll>(c+1,-1));


    vector<ll> arr(n);
    fore(i,0,n)cin>>arr[i];
    sort(arr.begin(),arr.end());

    dp[0][arr[0]] = arr[0];
    dp[0][0] = 0;
    fore(I,1,n){ 
        fore(i,0,c+1){
            dp[I%2][i] = -1;
        }
        int a = 2;
        fore(j,0,c+1){
            int i = I%2;
            //Si no lo meto:
            if(dp[(i+1)%2][j] != arr[I])
                dp[i][j] = max(dp[i][j], dp[(i+1)%2][j]);
            else{
                int indAntes = lower_bound(arr.begin(), arr.end(), dp[(i+1)%2][j]) - arr.begin();
                if(indAntes == 0){
                    dp[i][j] = max(dp[i][j], 0LL);
                } else{
                    dp[i][j] = max(dp[i][j], arr[indAntes-1]);
                }
            }

            //Si lo meto
            if((dp[(i+1)%2][j]==-1) || j+arr[I] > c) continue; //Puedo meterlo?
            
            //Metiendolo, cambia algo?
            if(dp[(i+1)%2][j]==arr[I-1]) dp[i][j+arr[I]] = max(dp[i][j+arr[I]], arr[I]);
            else dp[i][j+arr[I]] = max(dp[i][j+arr[I]], dp[(i+1)%2][j]);
        }
    }

    // fore(I,0,n+1){
    //     int i = I%2;
    //     fore(j,0,c+1){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    fore(j,0,c+1){
        ll cur = dp[(n-1)%2][j];
        if(cur == -1) continue;
        auto pt = upper_bound(arr.begin(),arr.end(), cur);
        if(pt == arr.end()){
            cout<<j<<endl;
            break;
        } else{
            if(j+(*pt) > c){
                cout<<j<<endl;
                break;
            }
        }
    }

    return 0;
}
