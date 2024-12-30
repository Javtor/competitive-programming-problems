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

    string s1, s2; cin>>s1>>s2;

    int alsz = 0;
    fore(i,0,s1.size()){
        if(s1[i] >='a' && s1[i]<='z') alsz++;
    }
    string as1 = s1.substr(0,alsz);
    string as2 = s2.substr(0,alsz);
    string ns1 = s1.substr(alsz,s1.size()-alsz);
    string ns2 = s2.substr(alsz,s2.size()-alsz);

    fore(i,0,max(0,SZ(ns2)-SZ(ns1))){
        ns1 = '0'+ns1;
    }

    fore(i,0,max(0,SZ(ns1)-SZ(ns2))){
        ns2 = '0'+ns2;
    }
    s1 = as1+ns1;
    s2 = as2+ns2;

    char c = '=';

    if(s1<s2) c = '<';
    else if (s2<s1) c = '>';

    cout<<c<<endl;
    
    return 0;
}
