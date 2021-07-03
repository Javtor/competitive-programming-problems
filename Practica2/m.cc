#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; i++)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007;
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    ll n, c, t;cin>>n>>c>>t;
    vector<ll> pop;
    while (n--)
    {
        ll p;
        cin >> p;
        pop.pb(p);
    }
    ll l = 0;
    ll r = 100000000000;
    ll ans = 0;

    //bin 1
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int count = 1;
        ll sec = m*t;
        ll acc = 0;
        bool pos = true;
        fore(i,0,pop.size()){
            int p = pop[i];
            if(p>sec){
                pos = false;
                break;
            }
            if(acc+p<=sec){
                acc+=p;
            } else{
                count++;
                acc=0;
                i--;
            }
        }
        if(count<=c && pos){
            r=m-1;
            ans = m;
        } else{
            l=m+1;
        }
    }
     //bin 2
    // while (l <= r)
    // {
    //     ll m = l + (r - l) / 2;
    //     ll count = 1;
    //     ll acc = 0;
    //     bool pos = true;
    //     fore(i,0,pop.size()){
    //         ll p = pop[i];
    //         ll seg = ceil((double)p/(double)t);
    //         if(seg>m){
    //             pos = false;
    //             break;
    //         }
    //         if(acc+seg<=m){
    //             acc+=seg;
    //         } else{
    //             count++;
    //             acc=0;
    //             i--;
    //         }
    //     }
    //     if(count<=c && pos){
    //         r=m-1;
    //         ans = m;
    //     } else{
    //         l=m+1;
    //     }
    // }
    cout<<ans;
    return 0;
}