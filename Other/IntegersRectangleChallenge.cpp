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

int mat[55][55];
int n,m;
ll psum[55][55];

long getsum(int i1, int j1, int i2, int j2){
    ll sum = psum[i2][j2];
    if(i1>0) sum-=psum[i1-1][j2];
    if(j1>0) sum-=psum[i2][j1-1];
    if(i1>0 && j1>0) sum+= psum[i1-1][j1-1];
    return sum;
}

int dp[55][55][55][55][3][2];

int go(int i, int j, int i1, int j1, int cual, int act){

    if(i == n || cual == 3) return 0;
    if(j == m) return go(i+1,0,i1,j1,cual,act);
    int &r = dp[i][j][i1][j1][cual][act];
    if(r != -1) return r;

    if(!act){ //poner esquina arriba izq
        int empiezo = go(i,j+1,i,j,cual,1);
        int espero = go(i,j+1,i1,j1,cual,0);
        r = max(empiezo,espero);
    } 
    if(act){ //poner esquina abajo der

    }


    return r;

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
    mset(mat,0);
    mset(psum,0);
    mset(dp,-1);
    cin>>n>>m;
    fore(i,0,n)fore(j,0,m)cin>>mat[i][j];
    
    fore(i,0,n)fore(j,0,m){
        psum[i][j] = mat[i][j];
        if(i>0) psum[i][j] += psum[i-1][j];
        if(j>0) psum[i][j] += psum[i][j-1];
        if(i>0 && j>0) psum[i][j] -= psum[i-1][j-1];
    }

    cout<<go(0,0,0,0,0,0)<<endl;
    return 0;
}
