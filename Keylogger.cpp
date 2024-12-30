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

const ll MOD = 1e9+7;
const ll maxk = 752;
const ll maxn = 1e4+10;
ll k,l,n;
vector<vector<ll>> ori(maxk,vector<ll>(maxk));
vector<vector<ll>> inf(maxk,vector<ll>(maxk));
vector<vector<ll>> sup(maxk,vector<ll>(maxk));

vector<vector<ll>> umois(maxn,vector<ll>(maxk));
vector<vector<ll>> pmois(maxn,vector<ll>(maxk));

ll p[maxn];


ll dp[10000+15][752];

// ll go(int i, int letra){
//     if(i==n-1) 
//         return 1;
//     ll &r = dp[i][letra];
//     if(r != -1) return r;
//     r = 0;

//     //primero busco en inf el ultimo menor o igual
//     int umoi = umois[i][letra];
//     if(umoi == -1) return r = 0;

//     //primero busco en sup el primero mayor o igual
//     int pmoi = pmois[i][letra];
//     if(pmoi == k) return r = 0;

//     fore(j,pmoi,umoi+1){
//         r = (r+go(i+1,j))%MOD;
//     }

//     return r;
// }

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    mset(dp,-1);
    cin>>k>>l;
    
    fore(i,0,k)fore(j,0,k){
        cin>>ori[i][j];
        inf[i][j] = ori[i][j]-l;
        sup[i][j] = ori[i][j]+l;
    }
    cin>>n;
    
    fore(i,0,n-1) cin>>p[i];   
    fore(i,0,n-1)fore(letra,0,k){
        ll umoi = upper_bound(inf[letra].begin(), inf[letra].begin()+k,p[i]) - inf[letra].begin() - 1;
        umois[i][letra] = umoi;

        ll pmoi = lower_bound(sup[letra].begin(), sup[letra].begin()+k,p[i]) - sup[letra].begin();
        pmois[i][letra] = pmoi;
    }

    

    fore(i,0,k){
        dp[n-1][i] = 1;
        if(i) dp[n-1][i]+=dp[n-1][i-1];
    }

    for(int i = n-2; i >=0; i--) {fore(letra, 0, k){
        dp[i][letra] = 0;

        if(letra) dp[i][letra] = (dp[i][letra]+dp[i][letra-1])%MOD;

        //busco en inf el ultimo menor o igual
        ll umoi = umois[i][letra];
        if(umoi == -1) continue;

        //busco en sup el primero mayor o igual
        ll pmoi = pmois[i][letra];
        if(pmoi == k) continue;

        ll asumar = dp[i+1][umoi];
        if(pmoi) asumar -= dp[i+1][pmoi-1];

        dp[i][letra] = (dp[i][letra] + asumar)%MOD;
    }

    }
        

    ll ans = dp[0][k-1]%MOD;

    cout<<ans<<endl;
    return 0;
}
