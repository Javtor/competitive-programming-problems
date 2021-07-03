#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define forn(i, n) for (int i=0 ; i<n ; i++)
#define fors(i, s) for (int i=0 ; i<s.size() ; i++)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


uint64 dp[7][50][4][4][4][4][4][4][4];
int mat[7][50];

uint64 solve(int i, int j, vector<int> frente, int N, int M, int K){
    if(i > 0 || j > 0){
        return 0;
    }
    if(j == M) return 1;
    if(dp[i][j][frente[0]][frente[1]][frente[2]][frente[3]][frente[4]][frente[5]][frente[6]] != -1)
        return dp[i][j][frente[0]][frente[1]][frente[2]][frente[3]][frente[4]][frente[5]][frente[6]];
    bool ocupado[K];
    MEM(ocupado,0);
    int posibilidades = K;

    uint64 ans = 0;
    if(i != 0){
        ocupado[frente[i-1]] = 1;
    }
    if(j != 0){
        ocupado[frente[i]] = 1;
    }
    forn(i2,K){
        if(ocupado[i2]){
            posibilidades--;
            if(i2 == mat[i][j]-1){
                return dp[i][j][frente[0]][frente[1]][frente[2]][frente[3]][frente[4]][frente[5]][frente[6]] = 0;

            }
        }
    }
    if(mat[i] != 0){
        forn(i2,K){
            if(!ocupado[i2]){
                VI copia(frente);
                copia[i] = i2;
                if(i < N-1){
                    ans += solve(i+1,j,copia,N,M,K)%MOD;
                    
                } else{
                    ans += solve(0,j+1,copia,N,M,K)%MOD;
                }
                ans%=MOD;
            }
        }
    } else{

    }

    return ans;

}

int main()
{
    MEM(dp,-1);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int N,M,K;
	cin >>N>>M>>K;
    
    forn(i,N){
        forn(j,M){
            char c;
            cin>>c;
            
            if(c=='-'){
                mat[i][j] = 0;
            } else{
                mat[i][j] = c-'0';
            }

        }

    }
    vector<int> frente{ 0,0,0,0,0,0,0};
    uint64 ans = solve(0,0,frente,N,M,K);
	return 0;
}