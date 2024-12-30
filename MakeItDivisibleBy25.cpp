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
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        string sor = s;
        int ia = 0,ib=0;

        ll tans = 1e9;

        //intento con 0
        s = sor;
        int i0 = s.find_last_of('0');
        if(i0!=-1){
            ll ans = SZ(s)-i0-1;
            s = s.substr(0,i0);
            ia = s.find_last_of('0');
            ib = s.find_last_of('5');
            if(ia!=-1 || ib!=-1){
                ans += SZ(s)-max(ia,ib)-1;
                tans = min(tans,ans);
            }            
        }
        
        //intento con 5
        s = sor;
        int i5 = s.find_last_of('5');                
        if(i5!=-1){ // 25 75
            ll ans = SZ(s)-i5-1;
            s = s.substr(0,i5);
            ia = s.find_last_of('2');
            ib = s.find_last_of('7');
            if(ia!=-1 || ib!=-1){
                ans += SZ(s)-max(ia,ib)-1;
                tans = min(tans,ans);
            }   
        } 
        cout<<tans<<endl;
    }
    
    return 0;
}
