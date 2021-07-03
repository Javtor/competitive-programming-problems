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

const double PI = acos(-1);
const double EPS = 1e-9;

ll damelo(int f, int b){
    return 12/__gcd(12,__gcd(f,b));
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

    int t;cin>>t;
    // cout<<damelo(3);
    while(t--){
        ll c,f,b,s;cin>>c>>f>>b>>s;
        double minF = damelo(f,b);
        
        ll numPasos = ceil(12.0*(double)s / (minF*c));
        cout<<(numPasos*minF)<<endl;
    }

    
    return 0;
}
