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

const ll MAXN = 1E10+15;

auto rnd=bind(uniform_int_distribution<long long>(1,MAXN), mt19937(time(0)));


int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    ll n;double p;cin>>n>>p;
    vector<ll> x(n);
    vector<ll> y(n);
    fore(i,0,n){
        cin>>x[i]>>y[i];
    }
    if(n==1){
        cout<<"possible"<<endl;return 0;
    }
    fore(intento,0,1000){
        int p1 = rnd()%n;
        int p2 = rnd()%n;
        while(p2==p1)p2=rnd()%n;
        int cnt = 1;
        fore(i,0,n){
            if(i == p1){
                continue;
            }
            if((y[p2]-y[p1])*(x[i]-x[p1]) == (y[i]-y[p1])*(x[p2]-x[p1]))cnt++;
            if(cnt*100>=p*n){
                cout<<"possible"<<endl;return 0;
            }
        }
    }
    cout<<"impossible"<<endl;
    return 0;
}
