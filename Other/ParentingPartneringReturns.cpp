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
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        string ans = "";
        int n;cin>>n;
        vector<int> st[24*60+1];
        vector<int> en[24*60+1];
        char resp[n];
        bool C = true;bool J = true;
        bool pos = true;

        set<int> sl;
        fore(i,0,n){
            int S,E;cin>>S>>E;
            st[S].pb(i);
            en[E].pb(i);
        }
        fore(i,0,24*60+1){
            fore(j,0,en[i].size()){
                int next = en[i][j];
                if(resp[next]=='C'){
                    C=!C;
                } else if(resp[next]=='J'){
                    J=!J;
                } else{
                    pos = false;break;
                }
            }
            fore(j,0,st[i].size()){
                int next = st[i][j];
                if(C){
                    resp[next]='C';C=!C;
                } else if(J){
                    resp[next]='J';J=!J;
                } else{
                    pos = false;break;
                }
            }
            
            if(!pos)break;
        }
        if(pos){
            fore(i,0,n){
                ans+=resp[i];
            }
        } else{
            ans = "IMPOSSIBLE";
        }
        cout << "Case #" << cs++ << ": " << ans << "\n";
    }

    return 0;
}
