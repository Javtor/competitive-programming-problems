#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

typedef vector<ll> vi;

struct Hash {
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(const vi &s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		fore(k,0,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			fore(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
	ll get(int s, int e){
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
}; 

ll hsum(ll h1, ll h2){
    int M1=999727999, M2=1070777777;
    ll h11 = h1>>32, h12 = h1 & ((1LL<<32)-1);
    ll h21 = h2>>32, h22 = h2 & ((1LL<<32)-1);
    ll h31 = (h11+h21) %M1, h32 = (h12+h22) %M2;
    return (h31<<32)|h32;
}

ll hsubs(ll h1, ll h2){
    int M1=999727999, M2=1070777777;
    ll h11 = h1>>32, h12 = h1 & ((1LL<<32)-1);
    ll h21 = h2>>32, h22 = h2 & ((1LL<<32)-1);
    ll h31 = (h11-h21+M1) %M1, h32 = (h12-h22+M2) %M2;
    return (h31<<32)|h32;
}

int n,m,c;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin>>n>>m>>c;
    vector<vi> mosaic(n);
    fore(i,0,n)fore(j,0,m){
        int aux;cin>>aux;aux--;mosaic[i].pb((aux));
    }
    vi hashes(n);
    fore(i,0,n){
        vi amount(c);
        fore(j,0,m){
            amount[mosaic[i][j]]++;
        }
        Hash w(amount);
        hashes[i]= w.get(0,c);
    }
    vector<vi> sums(n+1);

    vi nec(n+1,-1);
    fore(i,0,n+1){
        ll total = i*m;
        if(total%c == 0) {
            vi amount(c,total/c);
            Hash w(amount);
            nec[i]=w.get(0,c);
        }
    }

    fore(i,0,1<<(n/2)){
        ll sum = 0;
        fore(j,0,(n/2))if(i&(1<<j)){
            sum = hsum(sum,hashes[j]);
        }
        int pc = __builtin_popcount(i);
        sums[pc].pb(sum);
    }
    
    fore(i,0,n/2){
        sort(ALL(sums[i]));
    }
    int ans = 0;
    ll test = hsum(hsum(hashes[0],hashes[1]),hashes[2]);
    fore(i,0,1<<(n-n/2)){
        ll sum = 0;
        fore(j,0,(n-n/2))if(i&(1<<j)){
            sum = hsum(sum,hashes[n/2+j]);
        }
        int pc = __builtin_popcount(i);
        fore(k,max(ans+1,pc),n+1){
            if(nec[k] ==-1)continue;
            ll necesito = hsubs(nec[k],sum);
            auto cual = lower_bound(ALL(sums[k-pc]),necesito);
            if(cual != sums[k-pc].end() && *cual == necesito)
                ans = k;
        }
    }
    cout<<ans<<endl;
    return 0;
}
