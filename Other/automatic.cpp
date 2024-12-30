#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

const int MAXN = 1e5+10;

#define oper min
#define NEUT 1e9
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() {FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n; cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    STree st(MAXN);
    fore(i,0,n){
        cin>>v[i].fst.snd>>v[i].fst.fst;
        v[i].snd = i;
    }
    sort(ALL(v));
    int q; cin>>q;
    vector<pair<int,int>> qu(q);
    fore(i,0,q){
        cin>>qu[i].snd>>qu[i].fst;
    }
    sort(ALL(qu));
    ll ans = 0;
    int j = 0;
    fore(i,0,q){
        int a = qu[i].snd,b = qu[i].fst;
        while(j < n && v[j].fst.fst <= b){
            int aux = v[j].snd;
            if(st.query(v[j].fst.snd,v[j].fst.snd+1) > aux){
                st.upd(v[j].fst.snd,aux);
            }
            j++;
        }
        ll pos = st.query(a,MAXN);
        ans += pos+1;
    }
    cout<<ans<<"\n";
    return 0;
}
