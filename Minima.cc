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

const ll p32 = 1LL<<32;
const ll p31 = 1LL<<31;
const ll mod = 1LL<<32;

int n,m,k;
int a,b,c;
const int MAXN = 30000000+10;
int seq[MAXN];

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("minima.in", "r", stdin);
    freopen("minima.out", "w", stdout);
#define endl '\n'
#endif
    cin>>n>>m>>k;
    cin>>a>>b>>c;
    fore(i,0,k){
        int val;cin>>val;
        seq[i]=val;
    }

    fore(i,k,n){
        // __int128 z = a*seq[i-2]+b*seq[i-1]+ c;
        // int y = z%mod;
        // ll y = (((((a*seq[i-2])&bits) + ((b*seq[i-1])&bits))&bits) + c)&bits;
        int y = a*seq[i-2]+b*seq[i-1]+ c;
        if(y>(p31-1)){
            y -= (mod);
        }
        if(y<(-p31)){
            y += (mod);
        }
        // cout<<y<<"\n";
        seq[i]=y;
    }

    ll ans = 0;
    deque<pair<ll,int>> pq;
    fore(i,0,n){

        while(!pq.empty() && pq.front().second<=(i-m)){
            pq.pop_front();
        }
        while(!pq.empty() && pq.back().first>=seq[i]){
            pq.pop_back();
        }
        pq.pb({seq[i],i});
        if(i>=m-1){
            ans += pq.front().first;
        }
        //cout<<pq.top().first<<" "<<pq.top().second<<"\n";
    }
    cout<<ans<<endl;

    return 0;
}
