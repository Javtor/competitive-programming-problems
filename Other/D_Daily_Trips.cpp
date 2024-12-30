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
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

int main()
{ FIN;
    int n,h,w;cin>>n>>h>>w;
    vector<pair<bool,bool>> wea(n);
    vector<pair<bool,bool>> ans(n);
    fore(i,0,n){
        char a,b;cin>>a>>b;
        wea[i].fst = a=='Y';
        wea[i].snd = b=='Y';
    }
    fore(i,0,n){
        if(wea[i].fst || w==0){
            ans[i].fst = true;
            h--;w++;
        } 
        if(wea[i].snd || h==0){
            ans[i].snd = true;
            w--;h++;
        }
    }
    fore(i,0,n){
        cout<<(ans[i].fst?'Y':'N')<<' '<<(ans[i].snd?'Y':'N')<<endl;
    }
    return 0;
}