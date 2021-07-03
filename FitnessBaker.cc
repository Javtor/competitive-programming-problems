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

const int MOD=1e9+7;

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=(r*a)%MOD;
		e>>=1;a=(a*a)%MOD;
	}
	return r;
}
ll inv(ll a){return pm(a,MOD-2);}

struct intmod {  
	int x;
	intmod(int x2):x(x2){x2 = x2%MOD;if(x2<0)x2+=MOD;x=x2;}
    intmod(){}
	intmod operator+(intmod o){
        x+=o.x;
        if(x>=MOD)x-=MOD;
        return intmod(x);		
	}
    intmod operator-(intmod o){
        x-=o.x;
        if(x<0)x+=MOD;
        return intmod(x);		
	}
    intmod operator*(intmod o){
        ll mid = ((ll)x * (ll)(o.x))%MOD;
        return intmod(mid);		
	}
    intmod operator/(intmod o){
        
        return (x*inv(o.x))%MOD;		
	}
};



typedef ll tp; // type of polynomial
template<class T=tp>
struct poly {  // poly<> : 1 variable, poly<poly<>>: 2 variables, etc.
	vector<T> c;
	T& operator[](int k){return c[k];}
	poly(vector<T>& c):c(c){}
	poly(initializer_list<T> c):c(c){}
	poly(int k):c(k){}
	poly(){}
	poly operator+(poly<T> o){
		int m=c.size(),n=o.c.size();
		poly res(max(m,n));
		fore(i,0,m)res[i]=(res[i]+c[i])%MOD;
		fore(i,0,n)res[i]=(res[i]+o.c[i])%MOD;
		return res;
	}
	poly operator*(tp k){
		poly res(c.size());
		fore(i,0,c.size())res[i]=(c[i]*k)%MOD;
		return res;
	}
	poly operator*(poly o){
		int m=c.size(),n=o.c.size();
		poly res(m+n-1);
		fore(i,0,m)fore(j,0,n)res[i+j]=(res[i+j]+(c[i]*o.c[j])%MOD)%MOD;
		return res;
	}
	poly operator-(poly<T> o){return *this+(o*-1);}
	T operator()(tp v){
		T sum(0);
		for(int i=c.size()-1;i>=0;--i)sum=(sum*v+c[i])%MOD;
		return sum;
	}
};

pair<poly<>,tp> ruffini(poly<> p, tp r){ // returns pair (result,rem)
	int n=p.c.size()-1;
	vector<tp> b(n);
	b[n-1]=p[n];
	for(int k=n-2;k>=0;--k)b[k]=(p[k+1]+(r*b[k+1])%MOD)%MOD;
	return {poly<>(b),p[0]+r*b[0]};
}
// only for double polynomials
poly<> interpolate(vector<tp> x, vector<tp> y){
	poly<> q={1},S={0};
	for(tp a:x)q=poly<>({-a,1})*q;
	fore(i,0,x.size()){
		poly<> Li=ruffini(q,x[i]).fst;
		Li=Li*(inv(Li(x[i]))); // change for int polynomials
		S=S+Li*y[i];
	}
	return S;
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

    vector<ll> xs;
    vector<ll> ys;
    fore(n,1,8){
        set<int> blocked;

        fore(i,0,n)fore(j,0,n)blocked.insert(i*n*3+j);//arriba izq
        fore(i,0,n)fore(j,2*n,3*n)blocked.insert(i*n*3+j);//arriba der

        fore(i,2*n,3*n)fore(j,0,n)blocked.insert(i*n*3+j); //abajo izq
        fore(i,2*n,3*n)fore(j,2*n,3*n)blocked.insert(i*n*3+j);//abajo der

        int cnt = 0;
        fore(i,0,3*n)fore(j,0,3*n){
            if(blocked.count(i*n*3+j))continue;
            set<int> vis;
            queue<int> q;
            ll dis[n*n*9];
            dis[i*n*3+j] = 0;
            q.push(i*n*3+j);
            vis.insert(i*n*3+j);
            while(!q.empty()){
                int x=q.front();q.pop();
                int i1 = x/(n*3);
                int j1 = x%(n*3);

                //arriba
                if(i1>0){
                    int xn = (i1-1)*n*3+(j1);                    
                    if(!vis.count(xn) && !blocked.count(xn)){
                        vis.insert(xn);
                        dis[xn] = 1+dis[x];
                        cnt+=dis[xn];
                        q.push(xn);
                    }
                }

                //izq
                if(j1>0){
                    int xn = (i1)*n*3+(j1-1);                    
                    if(!vis.count(xn) && !blocked.count(xn)){
                        vis.insert(xn);
                        dis[xn] = 1+dis[x];
                        cnt+=dis[xn];
                        q.push(xn);
                    }
                }

                //abajo
                if(i1<3*n-1){
                    int xn = (i1+1)*n*3+(j1);                    
                    if(!vis.count(xn) && !blocked.count(xn)){
                        vis.insert(xn);
                        dis[xn] = 1+dis[x];
                        cnt+=dis[xn];
                        q.push(xn);
                    }
                }

                //der
                if(j1<3*n-1){
                    int xn = (i1)*n*3+(j1+1);                    
                    if(!vis.count(xn) && !blocked.count(xn)){
                        vis.insert(xn);
                        dis[xn] = 1+dis[x];
                        cnt+=dis[xn];
                        q.push(xn);
                    }
                }

                
	        }

        }
        cnt/=2;
        // cout<<cnt<<endl;
        xs.pb(n);
        ys.pb(cnt);
        
    }
    poly p = interpolate(xs,ys);
    ll N;
    while(cin>>N){
        N = N%MOD;
        ll res = ((p(N)%MOD+MOD)%MOD);
        cout<<res%MOD<<endl;
    }
    
    return 0;
}
