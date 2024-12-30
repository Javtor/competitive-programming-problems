#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)
typedef long long int ll;
using namespace std;

int main(){
    FIN;
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int n,k; cin>>n>>k;
    if(2*k>=n){
        ll ans = 0;
        fore(i,0,n){
            ll a; cin>>a;
            ans += a;
        }
        cout<<ans<<"\n";
        return 0;
    }
    ll a[n];
    ll sum[n], sum2[n];
    ll altans = -1;
    ll mx = -1;
    int ind = -1;
    ll ans = 0;
    fore(i,0,n){
        cin>>a[i];
        sum[i] = a[i]+(i>0?sum[i-1]:0);
        sum2[i] = a[i]+(i>0?sum2[i-1]:0);
        if(i>=k) sum[i]-=a[i-k];
        if(i>=2*k) sum2[i]-=a[i-2*k];
        if(sum2[i]>altans){
            altans = sum2[i];
        }
        if(sum[i] > mx){
            mx = sum[i];
            ind = i;
        }
    }
    ans += mx;
    ll b[n-k];
    int q = n-k-1;
    for(int i = n-1; i >= 0;i--){
        if(i==ind){
            ll cnt = 0;
            int j = i;
            while(cnt<k){
                j--;
                cnt++;
            }
            i = j+1;
        }else{
            b[q] = a[i];
            q--;
        }
    }
    
    mx = -1;
    fore(i,0,n-k){
        sum[i] = b[i]+(i>0?sum[i-1]:0);
        if(i>=k) sum[i]-=b[i-k];
        if(sum[i] > mx){
            mx = sum[i];
            ind = i;
        }
    }
    cout<<max(ans+mx,altans)<<"\n";
    return 0;
}