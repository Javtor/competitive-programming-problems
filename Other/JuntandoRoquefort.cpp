/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
*       Example:-   $ g++ -std=c++11 c++Template.cpp
*
* Author : Akshay Pratap Singh
* Handle: code_crack_01
*
*/
 
/********   All Required Header Files ********/
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

void anadirAVector(int inicio, const VI &graph, const VI &valores, vector<VI> &vectorPro, int D){
    int actual = inicio;
    VI vectorAct;
    
    while(vectorAct.size() < D && actual != -2){
        vectorAct.PB(valores[actual]);
        actual = graph[actual];
    }

    if(vectorAct.size() == D){
        reverse(all(vectorAct));
        vectorPro.PB(vectorAct);
    }

}

int main()
{

	#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int N,D;
	SCD(N);
    SCD(D);

    VI valores;
    VI graph;

	while(N--){
		int next;
        SCD(next);
        valores.PB(next);
	}
    N=valores.size();
    while(N--){
		int next;
        SCD(next);
        graph.PB(next-1);
	}
    N=valores.size();
    vector<VI> vectorPro;
    forn(i,N){
        anadirAVector(i,graph,valores,vectorPro,D);
    }
    VI ans = *max_element(all(vectorPro));
    forn(i,D){
        if(i != 0)
            cout << " ";
        cout << ans[i];
    }
    cout<<endl;
	return 0;
}