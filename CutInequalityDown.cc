#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF 1e17
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
    return mp(min(a.fst,b.fst), max(a.snd,b.snd));
}
#define NEUT mp(INF,-INF)

struct STree { // segment tree for min over integers
	vector<pair<ll,ll>> st;int n;
    STree(){}
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		if(s+1==e){st[k]={a[s],a[s]};return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]={v,v};return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<ll,ll> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
};

int N;
int L;
int U;
vector<ll> ps;
STree st;

pair<int, int> get(ll x, int ind){
    int l = ind+1; int r = N;
    pair<ll, int> ans = {N,0};
    while(l<=r){
        int m = l + (r-l)/2;
        pair<ll,ll> q = st.query(ind,m);
        if(ind > 0){
            q.fst-=ps[ind-1];
            q.snd-=ps[ind-1];
        }
        if(q.fst+x <= L || q.snd+x >= U){
            r = m-1;
            if(q.fst+x <= L){
                ans = {m, 0};
            } else{
                ans = {m, 1};
            }
        } else{
            l = m+1;
        }
    }
    return ans;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    cin >> N >> L >> U;
    st = STree(N);
    vector<ll> arr(N);
    fore(i,0,N){
        cin>>arr[i];
        ps.pb(arr[i]);
        if(i>0)ps[i]+=ps[i-1];
    }
    st.init(ps);

    int K = 17;
    pair<int, int> F[1<<K][2][K];
    fore(i,0,N){
		F[i][0][0]=get(i,L);
		F[i][1][0]=get(i,U);
	}
	F[N][0][0]=F[N][1][0]={N,0};
 
	fore(k,1,K) fore(i,0,N+1) fore(j,0,2){
		pair<int, int> myp=F[i][j][k-1];
		F[i][j][k]=F[myp.fst][myp.snd][k-1];
	}

    int Q; cin >> Q;
    while(Q--){
        int B, E, X;cin>>B>>E>>X;
        B--;E--;
        pair<int, int> este = get(X,B);
        if(este.fst >E+1){
            cout << X+ps[E]-(B?ps[B-1]:0) <<"\n";
        } else{
            for(int k=K-1;k>=0;k--) if(F[este.fst][este.snd][k].fst<=E+1){
				este=F[este.fst][este.snd][k];
			}
			ll ans=este.snd?U:L;
			ans+= ps[E]-(este.first?ps[este.fst-1]:0);
			cout << ans << "\n";
        }
    }

    return 0;
}
