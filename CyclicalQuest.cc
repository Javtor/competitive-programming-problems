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

struct state {int len,link;map<char,int> next;}; //clear next!!
const int MAXN  = 2000005;
state st[MAXN]; //2*MAXN
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

ll dp[MAXN];
bool term[MAXN];

ll go(int u){
    ll& r = dp[u];
    if(r != -1) return r;
    r = term[u];
    for(auto s : st[u].next){
        r += go(s.snd);
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
    mset(dp,-1);
    string S;cin>>S;
    sa_init();
    for(auto c : S) sa_extend(c);

    //Marco los terminales
    int termAc = last;
    while(termAc){
        term[termAc] = 1;
        termAc = st[termAc].link;
    }

    go(0);
    int q;cin>>q;
    while(q--){
        string x;cin>>x;
        int n = SZ(x);
        string k = x+x;
        k = k.substr(0,2*SZ(x)-1);
        ll ans = 0;
        int u = 0;
        int clen = 0;
        set<string> sets;
        fore(i,0,SZ(k)){
            while(u && !st[u].next.count(k[i]) ){
                u = st[u].link;
                clen = st[u].len;
            }
            if(st[u].next.count(k[i])){
                clen++;
                u = st[u].next[k[i]];
                if(clen == n) {
                    string subst = k.substr(i-n+1,n);
                    if(sets.count(subst)==0){
                        ans+=dp[u];
                        sets.insert(subst);
                    }
                }
            }
            if(clen == n){ //Elimino el caracter prefijo
                if(n == st[st[u].link].len + 1) 
                    u = st[u].link;
                clen--;
            }
        }

        cout<<ans<<endl;
    }
    
    return 0;
}
