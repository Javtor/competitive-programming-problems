#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<bool> visl(n+5);
        vector<bool> visr(n+5);
        vector<int> a(n);
        int maxl = 0, maxr = 0;
        int maxagl = 0, maxagr = 0;

        set<int> pl;
        set<int> pr;

        visl[0]=1;visr[0]=1;

        fore(i,0,n){
            cin>>a[i];
        }

        fore(i,0,n){
            if(visl[a[i]]) break;
            visl[a[i]] = true;
            maxagl = max(maxagl,a[i]);
            fore(j,maxl+1,visl.size()){
                
                if(!visl[j]){
                    maxl = j-1;
                    if(j==maxagl+1 && j > 1)
                        pl.insert(j-1);
                    break;
                }
            }
        }
        reverse(ALL(a));
        fore(i,0,n){
            if(visr[a[i]]) break;
            visr[a[i]] = true;
            maxagr = max(maxagr,a[i]);
            fore(j,maxr+1,visr.size()){
                
                if(!visr[j]){
                    maxr = j-1;
                    if(j==maxagr+1 && j > 1)
                        pr.insert(j-1);
                    break;
                }
            }
        }
        vector<pair<int,int>> ans;
        for(int asd : pl){
            if(pr.find(n-asd) != pr.end()) ans.pb({asd,n-asd});
        }
        cout<<ans.size()<<"\n";
        for(auto asd : ans){
            cout<< asd.fst<<" "<<asd.snd<<"\n";
        }
    }

    return 0;
}
