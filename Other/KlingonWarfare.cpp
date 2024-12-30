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
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));
const ll M = 1070777777;
struct Hash {
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(const vector<ll>& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		fore(k,0,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			fore(i,1,s.size()+1){
				h[k][i]=((h[k][i-1]+p*s[i-1])%MOD[k]+MOD[k])%MOD[k];
				pi[k][i]=((1LL*pi[k][i-1]*PI[k])%MOD[k]+MOD[k])%MOD[k];
				p=((p*P)%MOD[k]+MOD[k])%MOD[k];
			}
		}
	}
	ll get(int s, int e){
		ll h0=((h[0][e]-h[0][s]+MOD[0])+MOD[0])%MOD[0];
		h0=((1LL*h0*pi[0][s])+MOD[0])%MOD[0];
		ll h1=((h[1][e]-h[1][s]+MOD[1])+MOD[1])%MOD[1];
		h1=((1LL*h1*pi[1][s])+MOD[1])%MOD[1];
		return (h0<<32)|h1;
	}
};

const int MAXN = 2e4+15;

vector<int> g[MAXN];
ll sz[MAXN];
ll st[MAXN];
ll hsh[MAXN];
bool tieneHash[MAXN];

ll getHash(int i);

ll updSz(int i){
    ll s = 1;
    for(auto v : g[i]){
        s+=updSz(v);
    }
    sz[i]=s;
    return s;
}


ll getHash(int i){
    if(tieneHash[i]) return hsh[i];
    // auto vec = getVec(i);
    ll prime = 31;
    ll h = 1;
    // Hash h(vec);
    // hsh[i] = h.get(0,SZ(vec));
    int exp = 1;
    for(auto v : g[i]){
        h = h*prime+getHash(v)*prime*exp;
        exp++;
        // h%=M;
    }
    h = h*prime+st[i];
    h = h*prime+sz[i];
    // h%=M;
    hsh[i]=h;
    tieneHash[i]=1;
    return hsh[i];
}

void addtoSet(int i, set<ll>& s){
        s.insert(getHash(i));
        for(auto v : g[i]){
            addtoSet(v,s);
        }
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
    while(t--){
        for (auto& v : g) {
            v.clear();
        }
        mset(sz,0);
        mset(st,0);
        mset(hsh,0);
        mset(tieneHash,0);
        int m,n;cin>>m>>n;
        fore(i,0,m){
            char c;cin>>c;
            int par;cin>>par;
            st[i] = (c-'A');
            if(par != -1){
                g[par].pb(i);
            }
        }
        updSz(0);
        set<ll> todosA;
        addtoSet(0,todosA);

        fore(i,0,n){
            char c;cin>>c;
            int par;cin>>par;
            st[i+m] = c-'A';
            if(par!=-1){
                g[par+m].pb(i+m);
            }
        }
        updSz(m);
        // addtoSet(m,todosA);

        ll ans = 0;
        fore(i,0,n){
            int ind = i+m;
            if(sz[ind]>ans && todosA.count(getHash(ind))){
                ans = sz[ind];
            }
        }
        cout<<(int)ans<<'\n';
        int asd = 4;
    }
    return 0;
}
