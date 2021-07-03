#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define fore(i,a,b) for(int i = a, almo5t  = b; i < almo5t; i++)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007;
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main(){
    FIN;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    ll v, n;
    cin>>v>>n;
    ll a = v*n;
    int cnt = 1;
    while(cnt <= 9){
        ll aux = a*cnt;
        if((aux/10) == 0){
            if(cnt<9)
                cout<<1<<" ";
            else
                cout<<1;
        }else{
            ll ans = (aux/10)+(aux%10?1:0);
            if(cnt<9)
                cout<<ans<<" ";
            else
                cout<<ans;
            
        }
        cnt++;
    }
    return 0;
}