#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a, b) memset(a, b, sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

const int MAXN = 14;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n;
    ll L;

    cin >> n >> L;
    ll d[MAXN][MAXN];
    set<ll> s1;
    memset(d, 0, sizeof(d));
    fore(i, 0, n) fore(j, 0, n) cin >> d[i][j];

    int mid = 0;
    fore(i,1,n){
        mid = i;        
        fore(mask,0,1<<n){
            vector<int> m1;
            vector<int> m2;
            set<ll> s1;
            if((mask&1) || (mask&(1<<mid)) || __builtin_popcount(mask)!=((n-2)/2)) continue;
            fore(j,0,n){
                if(mask&(1<<j)) 
                    m1.pb(j);
                else if(j != 0 && j != mid) 
                    m2.pb(j);
            }
            do {
                ll dist = d[0][mid];
                if(m1.size()!=0){
                    dist = d[0][m1[0]];
                    fore(i,1,m1.size()){
                        dist+=d[m1[i]][m1[i-1]];
                    }
                    dist+=d[m1[m1.size()-1]][mid];
                }
                s1.insert(dist);
            } while (next_permutation(ALL(m1)));

            do {
                ll dist = d[0][mid];
                if(m2.size()!=0){
                    dist = d[0][m2[0]];
                    fore(i,1,m2.size()){
                        dist+=d[m2[i]][m2[i-1]];
                    }
                    dist+=d[m2[m2.size()-1]][mid];
                }

                if(s1.find(L-dist)!=s1.end()){
                    cout<<"possible"<<endl;
                    return 0;
                }
            } while (next_permutation(ALL(m2)));

        }
    }
    cout<<"impossible"<<endl;
    return 0;
}
