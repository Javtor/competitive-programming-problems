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

const int MAXN = 5e5+15;
bool ans = false;
string s;

int m;

vector<vector<pair<ll,char>>> g(MAXN);
vector<int> pleaf(MAXN);
vector<int> sleaf(MAXN);

ii dfs(int u, int p){ //{pref, suf}
    pair<ll,ll> r = {0,0};
    vector<ii> prefch;
    vector<ii> sufch;
    for(auto par : g[u]){
        int v = par.fst;
        char c = par.snd;
        if(v==p) continue;

        auto resch = dfs(v,u);

        if(ans)return r;

        if(resch.fst < m && c == s[resch.fst]){
            resch.fst++;
        }
        if(resch.snd < m && c == s[m-1-resch.snd]){
            resch.snd++;
        }
        prefch.pb({resch.fst, v});
        sufch.pb({resch.snd, v});
    }

    if(SZ(g[u]) == 1){ //Soy hoja
        pleaf[u]=u;
        sleaf[u]=u;
        return r;
    } 

    sort(ALL(prefch));
    sort(ALL(sufch));

    int sz = SZ(g[u])-1;

    pleaf[u] = pleaf[prefch[sz-1].snd];
    sleaf[u] = sleaf[sufch[sz-1].snd];
    r = {prefch[sz-1].fst, sufch[sz-1].fst};

    if(sz == 1){ //Solo tengo 1 hijo

        //Por prefijo
        if(r.fst >= m) {
            ans = true;
            cout<<(pleaf[u]+1)<<" "<<(u+1)<<endl;
            return r;
        }

        //Por sufijo
        if(r.snd >= m) {
            ans = true;
            cout<<(u+1)<<" "<<(sleaf[u]+1)<<endl;
            return r;
        }
        return r;

    } else{
        if(prefch[sz-1].snd != sufch[sz-1].snd){
            if(r.fst+r.snd>=m){
                ans = true;
                cout<<(pleaf[prefch[sz-1].snd]+1)<<" "<<(sleaf[sufch[sz-1].snd]+1)<<endl;
                return r;
            }
        } else{
            if(prefch[sz-1].fst + sufch[sz-2].fst >=m){
                ans = true;
                cout<<(pleaf[prefch[sz-1].snd]+1)<<" "<<(sleaf[sufch[sz-2].snd]+1)<<endl;
                return r;
            } else if (prefch[sz-2].fst + sufch[sz-1].fst >=m){
                ans = true;
                cout<<(pleaf[prefch[sz-2].snd]+1)<<" "<<(sleaf[sufch[sz-1].snd]+1)<<endl;
                return r;
            }
        }
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

    int n;cin>>n>>m;
    fore(i,0,n-1){
        int u,v;char c;cin>>u>>v>>c;
        u--;v--;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }
    g[0].pb({-1,'a'});
    cin>>s;
    dfs(0,-1);
    if(!ans){
        cout<<"-1 -1"<<endl;
    }
    int a = 3;
    return 0;
}
