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
const int MAXN  = 200005;
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

ll go(int u){
    ll& r = dp[u];
    if(r != -1) return r;
    r = 1;
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
    go(0);
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        int u = 0;
        string ans = "";
        while(k){
            for(auto s : st[u].next){
                if(dp[s.snd] < k){
                    k-=dp[s.snd];
                } else{
                    ans+=s.fst;
                    u = s.snd;
                    k--;
                    break;
                }
            }
        }
        cout<< ans<<endl;
    }
    return 0;
}
