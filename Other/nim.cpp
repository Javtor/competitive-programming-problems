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
#define sz(x) ((int)x.size())
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
    vector<bool> gana;
    gana.pb(1);
    gana.pb(1);
    int probar = 100000;
    fore(i,2,probar+1){
        int hastaCuantos = sqrt(i);
        gana.pb(0);
        fore(j,1,hastaCuantos+1){
            if(!gana[i-j]){
                gana[i]=1;
                break;
            }
        }
    }
    int cnt = 0;
    int ultimocnt = 0;
    int cuantosseguidos = 1;
    fore(i,1,probar+1){
        if(gana[i])cnt++;
        else{
            cout<<i<<endl;
            // cout<<cnt<<' ';
            // if(cnt == ultimocnt){
            //     cuantosseguidos++;
            // } else{
            //     cout<<cuantosseguidos<<endl;
            //     cuantosseguidos=1;
            // }
            // cout<<endl;
            // ultimocnt=cnt;
            // cnt = 0;
            // cuantosseguidos = 3;
            // cout<<0<<endl;
        }
        // cout<<gana[i]<<endl;
    }
    return 0;
}
