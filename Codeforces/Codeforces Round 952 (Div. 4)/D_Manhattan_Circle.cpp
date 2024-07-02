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

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    fore(i,0,n)fore(j,0,m){
        cin>>grid[i][j];
    }
    ii top = {-1,-1};
    bool found = false;
    fore(i,0,n)fore(j,0,m){
        if(grid[i][j]=='#' && !found){found=true; top={i,j};}
    }
    int sz = 0;
    for(int i = top.fst; i < n; i++){
        if (grid[i][top.snd] == '#'){
            sz++;
        }
    }
    cout<<(top.fst+(sz/2))+1<<' '<<top.snd+1<<endl;
}

int main(){FIN;
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
