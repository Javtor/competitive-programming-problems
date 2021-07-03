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
#define sz(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MAXN = 1<<21;
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0); // FFT
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
//CD root(int n, bool inv){ // NTT
//	int r=pm(RT,(MOD-1)/n); // pm: modular exponentiation
//	return CD(inv?pm(r,MOD-2):r);
//}
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n; // FFT
	//if(inv){ // NTT
	//	CD z(pm(n,MOD-2)); // pm: modular exponentiation
	//	fore(i,0,n)a[i]=a[i]*z;
	//}
}
vector<int> multiply(vector<int>& p1, vector<int>& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	vector<int> res;
	n-=2;
	fore(i,0,n)res.pb((int)floor(cp1[i].real()+0.5)); // change for NTT
	return res;
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
    int n,m;cin>>n>>m;
    vector<int> aa(n);
    vector<int> bb(m);
    string sa;cin>>sa;
    string sb;cin>>sb;
    vector<int> posic(n-m+1);
    vector<set<int>> ans(m+1);

    fore(i,0,n)aa[i]=(sa[i]=='a');
    fore(i,0,m)bb[m-i-1]=(sb[i]=='b');
    
    auto ma = multiply(aa,bb);
    fore(i,0,n-m+1){
        int ind = m-1+i;
        posic[i]+=ma[ind];
    }

    fore(i,0,n)aa[i]=(sa[i]=='b');
    fore(i,0,m)bb[m-i-1]=(sb[i]=='a');
    ma = multiply(aa,bb);

    fore(i,0,n-m+1){
        int ind = m-1+i;
        int sum = posic[i]+ma[ind];
        ans[sum].insert(i+1);
    }
    fore(i,0,m+1){
        cout<<i<<": ";
        for(auto in : ans[i])cout<<in<<' ';
        cout<<"\n";
    }
    return 0;
}
