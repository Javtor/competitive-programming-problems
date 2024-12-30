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
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=-1;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(lazy[k]==-1)return; // if neutral, nothing to do
		st[k]=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<STree> smts;
    int arrs[26][n];
    mset(arrs,0);
    fore(i,0,n){
        arrs[(s[i]-'a')][i]=1;
    }
    fore(i,0,26){
        STree rmq(n);
        rmq.init(arrs[i]);
        smts.pb(rmq);
    }
    while(q--){
        int x,y,k;cin>>x>>y>>k;
        vector<int> cnt(26);
        fore(i,0,26){
            cnt[i]=smts[i].query(x-1,y);
            smts[i].upd(x-1,y,0);
        }
        if(k){
            int last = x-1;
            fore(i,0,26){
                if(!cnt[i])continue;
                smts[i].upd(last,last+cnt[i],1);
                last = last+cnt[i];
            }
        } else{
            int last = x-1;
            for(int i = 25;i>=0;i--){
                if(!cnt[i])continue;
                smts[i].upd(last,last+cnt[i],1);
                last = last+cnt[i];
            }
        }
    }
    fore(i,0,n){
        fore(j,0,26){
            if(smts[j].query(i,i+1)){cout<<(char)(j+'a');}
        }
    }
    // smts[0].upd(0,3,0);
    // cout<<smts[0].query(0,n);
    // return 0;
}
