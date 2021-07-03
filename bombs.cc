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
#define INF 1e9
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

#define oper max
#define NEUT {-INF,0}
struct STree { // segment tree for min over integers
	vector<pair<int,int>> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<pair<int,int>> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, pair<int,int> v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<int,int> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<pair<int,int>> &a){init(1,0,n,a);}
	void upd(int p, pair<int,int> v){upd(1,0,n,p,v);}
	pair<int,int> query(int a, int b){return query(1,0,n,a,b);}
};

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> x;
    vector<pair<int,int>> intervs;
    vector<pair<int,int>> intervsearch;
    set<pair<int,int>> maxs;
    fore(i,0,n){
        cin>>a[i];
        x.pb({a[i],i});
        intervs.pb({0,n});
        intervsearch.pb({0,i+1});
    }
    STree rmq(n);rmq.init(x);
    pair<int,int> ma = rmq.query(0,n);
    cout<<ma.fst;

    int q; cin >> q;q--;
    int mayorind = q;

    fore(i,0,q+1){
        maxs.insert({-a[i],i});
    }
    ma = rmq.query(0,q+1);
    maxs.erase({-(ma.fst), ma.snd});
    cout<<" "<< max(-(*maxs.begin()).fst , rmq.query(mayorind+1,n).fst);
    fore(i,0,n){
        if(i <= ma.snd){
            intervsearch[i].second = min(intervsearch[i].second, ma.snd);
        } else{
            intervsearch[i].first = max(ma.snd, intervsearch[i].first);
        }
    }

    fore(i,0,n-2){
        cin >> q;q--;
        if(q > mayorind){
            fore(i,mayorind+1,q+1){
                maxs.insert({-a[i],i});
            }
        } 
        pair<int,int> is = intervsearch[q];
        ma = rmq.query(is.fst,is.snd);
        maxs.erase({-(ma.fst), ma.snd});

        fore(i,0,n){
        if(i <= ma.snd){
            intervsearch[i].second = min(intervsearch[i].second, ma.snd);
        } else{
            intervsearch[i].first = max(ma.snd, intervsearch[i].first);
        }
        }

        cout<<" "<< max(-(*maxs.begin()).fst , rmq.query(mayorind+1,n).fst);
    }
    
    int asdasd=0;
    return 0;
}
