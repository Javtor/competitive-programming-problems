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
    int cs = 1;
    while(t--){
        int n;cin>>n;
        int mat[n][n];
        fore(i,0,n)fore(j,0,n)cin>>mat[i][j];
        int trace = 0;
        fore(i,0,n) trace+=mat[i][i];

        int r = 0;
        fore(i,0,n){
            set<int> s;
            fore(j,0,n){
                int a = mat[i][j];
                if(s.find(a)!=s.end()){
                    r++; break;
                }
                s.insert(a);
            }
        }

        int c = 0;
        fore(i,0,n){
            set<int> s;
            fore(j,0,n){
                int a = mat[j][i];
                if(s.find(a)!=s.end()){
                    c++; break;
                }
                s.insert(a);
            }
        }
        cout <<"Case #"<<cs++<<": "<<trace<<" "<<r<<" "<<c<<"\n";

    }

    return 0;
}
