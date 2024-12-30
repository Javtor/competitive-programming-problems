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

typedef __int128 ll;

ll scan(){
    long long num;cin>>num;
    return num;
}

void print(ll x){
    cout<<(long long)x<<endl;
}

int b;
ll n;

const int MAXN = 1e4+10;
vector<int> primes;
vector<ll> divisors;
int cr[MAXN];
void init_sieve(){
    memset(cr,-1,sizeof(cr));
    fore(i,2,MAXN)if(cr[i]<0){primes.pb(i);for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;}
}

map<ll,ll> dp;

ll go(ll k, ll last){
    if(dp.count(k)) return dp[k];
    if(k<b) return k;
    ll x = -1;
    for(int i = SZ(divisors)-1;i>=0;i--){
        ll d = divisors[i];
        if(k%d!=0) continue;
        // if(k%d!=0 || (last != -1 && d>last)) continue;
        ll k1 = k/d;
        ll tst = go(k/d, last);
        if(tst == -1) continue;
        ll currans = tst*b+d;
        if(x==-1) x= currans;
        x = min(x, currans);
    }
    dp[k]=x;
    return x;
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
    cin>>b; init_sieve();
    n = scan();
    if(n<b) {
        print(n);
        return 0;
    }
    ll auxn = n;
    for(auto x: primes){
        if(x*x>auxn) break;
        while(n > 1 && n%x==0){
            n/=x;
        }
    }
    if(n>=b) {cout<<"impossible"; return 0;}
    fore(i,0,b){
        if(i*i<b) continue;
        if(auxn%i==0)divisors.pb(i);
    }
    print(go(auxn, -1));
    return 0;
}
