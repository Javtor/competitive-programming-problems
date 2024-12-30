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
    int n;cin>>n;
    int a = 0, b = 0;
    int ca = 0, cb = 0;
    deque<int> c;
    fore(i,0,n){
        int next;cin>>next;c.pb(next);
    }
    while(!c.empty()){
        if(a!=0)a--;
        if(b!=0)b--;
        if(a==0){
            a=c[0];
            ca++;
            c.pop_front();
        }
        if(b==0){
            if(c.empty())break;
            else{
                b=c[SZ(c)-1];
                cb++;
                c.pop_back();
            }
        }
    }
    cout<<ca<<' '<<cb;
    return 0;
}
