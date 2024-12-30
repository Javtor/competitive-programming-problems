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

    int vc[100000];
    int mn = -11;
    int mx = 3.65e7;

    vc[0] = mn;
    int sz = 1;
    double delta = 7.5e-5;
    double sl = sin(vc[0]);
    fore(i,mn+1,mx){
        double si = sin(i);
        if(si < sl && sl-si<delta ){vc[sz]=i;sz++;sl=si;}
    }
    int n = 50000;
    fore(i,0,n){
        cout<<vc[i]<<endl;
    }
    return 0;
}
