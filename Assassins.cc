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
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n,m;cin>>n>>m;
    //1 = muerto
    vector<double> probs(1<<n); //Probabilidad de que, al empezar el evento, haya ocurrido este estado
    vector<double> probActual(1<<n); //Probabilidad de llegar al estado en el evento actual
    probs[0]=1;
    fore(i,0,m){
        probActual.clear();
        probActual.resize(1<<n);
        int u,v;double p;cin>>u>>v>>p;
        u--;v--;
        fore(mask,0,1<<n){
            if(mask & ((1<<u)|(1<<v))){probActual[mask]+=probs[mask];continue;}//Si alguno esta muerto, ignoro el caso
            probActual[mask]+=probs[mask]*(1-p);
            probActual[mask|(1<<v)]+=probs[mask]*(p);
        }
        swap(probs,probActual);
    }
    vector<double> muerto(n);
    fore(i,0,1<<n){
        fore(j,0,n){
            if(i&(1<<j))
                muerto[j]+=probs[i];
        }
    }
    fore(i,0,n){
        cout<<fixed<<setprecision(12)<<1-muerto[i]<<'\n';
    }
    return 0;
}
