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
    freopen("kebab.in", "r", stdin);
    freopen("kebab.out", "w", stdout);
#define endl '\n'
#endif
    int b,k,cd,cp;cin>>b>>k>>cd>>cp;
    vector<ii> dir;vector<ii> por;
    fore(i,0,cd){
        ll d;cin>>d;
        dir.pb({d,i+1});
    }
    fore(i,0,cp){
        ll p;cin>>p;
        por.pb({p,i+1});
    }
    sort(dir.rbegin(),dir.rend());
    sort(por.rbegin(),por.rend());
    
    vector<ll> pd(cd), pp(cp);
    fore(i,0,cd){
        pd[i]=dir[i].fst;
        if(i)pd[i]+=pd[i-1];
    }
    fore(i,0,cp){
        pp[i]=por[i].fst;
        if(i)pp[i]+=pp[i-1];
    }

    pd.insert(pd.begin(),0);
    pp.insert(pp.begin(),0);

    ll mx = b;
    ll n = 0;
    ll m = 0;
    fore(i,0,min(k,cd)+1){
        int j = min(k-i,cp);
        ll act = (b+pd[i])*(100+pp[j]);
        if(act>mx){
            mx=act;
            n=i;m=j;
        }
    }
    cout<<n<<' '<<m<<endl;
    fore(i,0,n){
        if(i)cout<<' ';
        cout<<(dir[i].second);
    }
    cout<<endl;
    fore(i,0,m){
        if(i)cout<<' ';
        cout<<(por[i].second);
    }
    cout<<endl;
    return 0;
}
