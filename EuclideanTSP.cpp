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
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

double n,p,s,v;

double cost(double c){
    double rt = (n*pow(log2(n),c*sqrt(2)))/(p*1e9);
    double vuelo = s*(1+1/c)/v;
    return rt+vuelo;
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
    cin>>n>>p>>s>>v;
    int times = 200;
    double l = 0, r = 1000;
    double ans = 1e10;
    double C = 1e10;
    while(times--){
        
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        ans = cost(l+(r-l)/2);
        C = l+(r-l)/2;
        if(cost(m1)<=cost(m2)){
            r=m2;
        } else{
            l=m1;
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<' '<<C;
    return 0;
}
