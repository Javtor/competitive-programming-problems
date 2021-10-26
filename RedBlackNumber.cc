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

int n,A,B;
string s;
bool vis[45][45][45][45]; //i, cuantos rojos, mod de los rojos, mod de los negros
int res =1e9;
string ans = "";

void go(int i, int rojos, int mr, int mn){
    if(i==n){
        if(rojos>0 && rojos<n && mr+mn==0){
            res = min(res,abs(n-2*rojos));         
        }
        return;
    }
    char c = s[i];
    //rojo
    if(!vis[i+1][rojos+1][(mr*10+c-'0')%A][mn]){
        vis[i+1][rojos+1][(mr*10+c-'0')%A][mn] = 1;
        go(i+1,rojos+1,(mr*10+c-'0')%A,mn);
    }
    //negro
    if(!vis[i+1][rojos][mr][(mn*10+c-'0')%B]){
        vis[i+1][rojos][mr][(mn*10+c-'0')%B] = 1;
        go(i+1,rojos,mr,(mn*10+c-'0')%B);
    }
}

bool go2(int i, int rojos, int mr, int mn){
    if(i==n){
        if(rojos>0 && rojos<n && mr+mn==0 && abs(n-2*rojos)==res){
            return true;
        }
        return false;
    }
    char c = s[i];
    //rojo
    if(!vis[i+1][rojos+1][(mr*10+c-'0')%A][mn]){
        vis[i+1][rojos+1][(mr*10+c-'0')%A][mn] = 1;
        bool aqui = go2(i+1,rojos+1,(mr*10+c-'0')%A,mn);
        if(aqui){ 
            ans+='R';
            return true;
        }
    }
    //negro
    if(!vis[i+1][rojos][mr][(mn*10+c-'0')%B]){
        vis[i+1][rojos][mr][(mn*10+c-'0')%B] = 1;
        bool aqui = go2(i+1,rojos,mr,(mn*10+c-'0')%B);
        if(aqui){ 
            ans+='B';
            return true;
        }
    }
    return false;
}

void solve(){
    cin>>n>>A>>B;
    cin>>s;
    res = 1e9;
    mset(vis,0);

    go(0,0,0,0);
    mset(vis,0);

    if(res==1e9){
        cout<<-1<<endl;
    } else{
        ans = "";
        go2(0,0,0,0);
        reverse(ALL(ans));
        cout<<ans<<endl;
    }
    
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int t;cin>>t;while(t--)solve();
    return 0;
}
