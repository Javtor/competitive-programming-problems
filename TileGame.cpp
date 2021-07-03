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

typedef vector<int> vi;

vector<vi> ru(const vector<vi> &b){
    vector<vi> clon(b.size());
    fore(i,0,b.size()){
        fore(j,0,b[0].size()) clon[i].pb(-1);
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
        int r,c;cin>>r>>c;
        vector<vector<int>> board(r);
        fore(i,0,r)fore(j,0,c){
            char C;cin>>C;
            if(C=='.')board[i].pb(-1);
            else board[i].pb(i);
        }
    }
    return 0;
}
