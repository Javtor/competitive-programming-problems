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
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

struct palindromic_tree{
    static const int SIGMA =26;
    struct Node{
        int len,link,to[SIGMA];
        ll cnt, val;
        Node(int len, int link=0,ll cnt = 1, ll val=0):len(len),link(link),cnt(cnt), val(val){memset(to,0,sizeof(to));}
    };
    vector<Node> ns;
    int last;
    ll pow[100010];
    const ll a = 1e5+1, MOD = 1e9+7;
    palindromic_tree():last(0){ns.pb(Node(-1,0,1,0));ns.pb(Node(0,0,1,0));
        pow[0] = 1;
        fore(i,1,100010) pow[i] = (pow[i-1]*a)%MOD;
        pow[0] = 0;
    }
    void add(int i, string &s){
        int p=last, c=s[i]-'a'; ll d = (int)s[i];
        if(i-ns[p].len-1==-1) p=0;
        else while(s[i-ns[p].len-1]!=s[i]) 
            p=ns[p].link;
        if(ns[p].to[c]){
            last=ns[p].to[c];
            ns[last].cnt++;
        }else{
            int q= ns[p].link;
            while(s[i-ns[p].len-1]!=s[i])q=ns[q].link;
            q=max(1,ns[q].to[c]);
            last=ns[p].to[c]=SZ(ns);
            ll nval = ((d+(ns[p].val*a)%MOD)%MOD + (d*pow[ns[p].len+1])%MOD)%MOD;
            ns.pb(Node(ns[p].len+2,q,1,nval));
        }
    }
};

set<pair<string,pair<ll,ll>>> st;
palindromic_tree pl;

void dfs1(int u, string &curr){
    if(SZ(curr)) st.insert({curr,{pl.ns[u].cnt,pl.ns[u].val}});
    string aux = curr;
    for(char c = 'a'; c <= 'z'; c++){
        int x = c-'a';
        if(pl.ns[u].to[x]){
            if(!SZ(curr)) curr.pb(c);
            else{ curr = c+curr; curr.pb(c);}
            dfs1(pl.ns[u].to[x],curr);
            curr = aux;
        }
    }
}

void dfs2(int u, string &curr){
    if(SZ(curr)) st.insert({curr,{pl.ns[u].cnt,pl.ns[u].val}});
    string aux = curr;
    for(char c = 'a'; c <= 'z'; c++){
        int x = c-'a';
        if(pl.ns[u].to[x]){
            curr = c+curr; curr.pb(c);
            dfs2(pl.ns[u].to[x],curr);
            curr = aux;
        }
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
    int n,nq; cin>>n>>nq;
    string s; cin>>s; reverse(ALL(s));
    fore(i,0,n) pl.add(i,s);
    string t;
    dfs1(0,t); dfs2(1,t);
    for(auto x: st){
        cout<<x.fst<<" "<<x.snd.fst<<" "<<x.snd.snd<<"\n";
    }
    return 0;
}
