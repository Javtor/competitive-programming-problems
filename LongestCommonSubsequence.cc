#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin, cont.end
#define foreach(it, l) for(auto it = l.begin(); it != l.end; it++)
#define fore(i,a,b) for(ll i = a, almo5t = b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

const int N = 1e5 + 5;
const int K = 26;
int n;
int k;

string strings[N];
vector<vector<int>> g(K);


vector<bool> visited;
vector<int> ans;
vector<int>  dp;

/*void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for(auto i = ans.begin() ;i != ans.end() ;i++){
        cout<<*i<<"\n";
    }
}*/

void dfsDP(int v){

    visited[v] = true;

    for(auto a = g[v].begin(); a != g[v].end(); a++){
        int child = *a;
        //cout<<v<<" go "<<child<<" ";
        if(!visited[child])dfsDP(child);
        
        dp[v] = max(dp[v],1+dp[child]);
    }  

}

int findLongestPath(){
    visited.assign(k,false);
    dp.assign(k,0);
    
    fore (i,0,k) {
        if (!visited[i])
            dfsDP(i);
    }
    int ans = 0;
    
    fore (i,0,k) {
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(){    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin>>n>>k;
    fore(i,0,n){
        cin>>strings[i]; 
    }

    map<pair<int,int>,int> pairCheck;
    //cout<<(pairCheck[{0,0}]); 
    fore(e,0,n){
        fore(i,0,k){ 
            fore(j,i+1,k){
                pairCheck[{strings[e][i],strings[e][j]}] = (pairCheck[{strings[e][i],strings[e][j]}]+1);
            }
        }
    }

    for(auto itr = pairCheck.begin(); itr != pairCheck.end(); ++itr){
        int elems = (itr->second);
        if(elems < n) continue;
        int a = (itr->first).fst - 65;
        int b = (itr->first).snd - 65;
        //cout<<a<<" "<<b<<" "<< elems<< "\n";
        g[a].push_back(b);
    }
    


    //topological_sort();

    int longestPath = findLongestPath()+1;
    cout<<longestPath<<endl;
}   