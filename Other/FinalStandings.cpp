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

double dp[115][115];

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int t,p;cin>>t>>p;
    vector<double> s(t-1);
    vector<double> d(p);
    fore(i,0,t-1)cin>>s[i];
    fore(i,0,p)cin>>d[i];
    char resolv[t][p];
    fore(i,0,t)
        fore(j,0,p){
            char c;cin>>c;
            resolv[i][j]=c;
        }

    
    mset(dp,0.0);
    fore(i,0,t)dp[i][0]=1;

    fore(i,0,p){
        fore(j,0,t-1){
            vector<double> probActual(p+1,0);
            fore(k,0,p){
                double probres=s[j]*d[i];
                if(resolv[j][i]=='X')probres=1;
                if(resolv[j][i]=='-')probres=0;
                probActual[k]+=dp[j][k]*(1-probres);
                probActual[k+1]+=dp[j][k]*(probres);
            }
            fore(k,0,p+1){
                dp[j][k]=probActual[k];
            }
        }
    }
    int respormi=0;
    fore(i,0,p+1){
        if(resolv[t-1][i]=='X')respormi++;
    }
    double prob = 1;
    fore(i,0,t-1){
        double probac = 0;
        fore(j,0,respormi+1){
            probac+=dp[i][j];
        }
        prob*=probac;
    }
    cout<<fixed<<setprecision(12)<<prob<<'\n';
    return 0;
}
