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
const int MAXN2 = 1e3+5;
const int MAXN = 1e5+5;

int cr[(MAXN)]; // -1 if prime, some not trivial divisor if not
vector<int> primes;
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0){primes.pb(i);for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;}
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	for(auto pr:primes){
        while(n%pr==0){
            r[pr]++;
            n/=pr;
        }
    }
    if(n>1)r[n]++;
	return r;
}

vector<int> g[MAXN2];
vector<int> val;
vector<int> ans;
bool hoja[MAXN2];
vector<map<int,int>> facts;
bool pos = 1;
map<ll,bool> dp[MAXN2];

ll gcd(ll a, ll b){
    if(a==0)return b;
    if(b==0)return a;
    return __gcd(a,b);
}

ll dfs1(int i){
    ll v = max(0,val[i]);

    for(auto u : g[i]){
        v = gcd(v,dfs1(u));
    }
    val[i] = v;
    return v;
}

bool go(int i, ll valor){
    if(dp[i].count(valor)>0) 
        return dp[i][valor];
    bool pos = 1;

    for(auto v:g[i]){
        if(valor>=val[v]) pos = 0;
    }

    if(pos) for(auto v:g[i]){
        bool posLocal = 0;
        for(auto fc : facts[v]){
            if((val[v]%(valor*fc.first))==0){
                bool posll = go(v,valor*fc.first);
                if(posll){
                    ans[v]=hoja[v]? val[v]: valor*fc.first;
                    posLocal=1;
                    break;
                }
            }
        }
        pos = pos&posLocal;
    }

    dp[i][valor]=pos;
    return pos;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("divisibility-tree.in", "r", stdin);
    freopen("divisibility-tree.out", "w", stdout);
#define endl '\n'
#endif
    mset(hoja,0);
    init_sieve();
    int n;cin>>n;
    val.resize(n);
    ans.resize(n);
    facts.resize(n);
    fore(i,0,n){
        int a,p;cin>>p>>a;
        val[i]=a;
        if(p!=-1){
            g[--p].pb(i);
            
        }
        if(val[i]!=-1)hoja[i]=1;
    }
    dfs1(0);
    fore(i,0,n){
        auto m = fact(val[i]);
        facts[i]=m;
    }
    ans[0]=1;
    bool puedo = go(0,1);
    if(puedo){
        fore(i,0,n){
            cout<<ans[i]<<' ';
        }
    } else{
        fore(i,0,n){
            cout<<-1<<' ';
        }
    }
    return 0;
}
