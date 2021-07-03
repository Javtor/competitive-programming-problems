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

const int MAXN = 200005;

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[2*MAXN]; //2*MAXN
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)
        st[p].next[c]=k;
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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    string a,b;
    cin>>a;cin>>b;
    sa_init();
    fore(i,0,SZ(b)){
        sa_extend(b[i]);
    }
    
    string maxsuf = "";
    state stt = st[0];
    while(SZ(stt.next)){
        char car = (*(--stt.next.end())).first;
        maxsuf += car;
        stt = st[stt.next[car]]; 
    }

    //limpio el automata
    fore(i,0,2*MAXN){
        st[i].len = 0;
        st[i].link = 0;
        st[i].next.clear();
    }
    sa_init();
    fore(i,0,SZ(a)){
        sa_extend(a[i]);
    }
    string pref = "";
    bool primer =1;
    stt = st[0];
    while(SZ(stt.next)){
        char car = (*(--stt.next.end())).first;
        if(primer)
            pref += car;
        if(!primer){
            if(car>=maxsuf[0]){
                pref += car;
            } else
            {
                break;
            }      
        }
        primer = 0;
        stt = st[stt.next[car]]; 
    }
    cout<<pref+maxsuf<<endl;
    return 0;
}
