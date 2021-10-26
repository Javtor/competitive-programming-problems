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
    string s;cin>>s;
    int u=0,l=0;
    fore(i,0,SZ(s)){
        if(s[i]>='A'&&s[i]<='Z'){
            u++;
        } else l++;
    }
    fore(i,0,SZ(s)){
        if(u>l){
            s[i]=toupper(s[i]);
        } else s[i]=tolower(s[i]);
    }
    cout<<s;
    
    return 0;
}
