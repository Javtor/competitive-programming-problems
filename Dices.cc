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
 
const ll MOD = 1e9+7;
ll pm(ll a, ll e){
    ll r=1;
    while(e){
        if(e&1)r=r*a%MOD;
        e>>=1;a=a*a%MOD;
    }
    return r%MOD;
}
ll inv(ll a){return pm(a,MOD-2);}
 
typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)
		r[i][j]+=(a[i][k]*b[k][j])%MOD,r[i][j]%=MOD;
	return r;
}
Matrix be(Matrix b, ll e) {
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
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
    long long n,k,m;cin>>n>>k>>m;
    vector<ll> c(m,0);
    int smm = 0;
    fore(i,1,k+1){
        if(i%m!=0)smm++;
    }
    fore(i,1,k+1){
        if(i%m==0)continue;
        ll mod = i%m;
        c[mod]+= ( inv(smm) )%MOD;
        
    }
    Matrix probs(m,vector<ll>(m,0));
    fore(i,0,m)fore(j,0,m){
        int falta = (m+j-i)%m;
        assert(falta>=0 && falta<m);
        probs[i][j] = c[falta];
    }
    Matrix res = be(probs,n);
    cout<<(long long int)res[0][0]<<endl;
    return 0;
}