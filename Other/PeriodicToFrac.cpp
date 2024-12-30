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

typedef ll tipo;

tipo mcd(tipo a, tipo b){return a?mcd(b%a, a):b;}
struct frac{
	tipo p,q;
	frac(tipo p=0, tipo q=1):p(p),q(q) {norm();}
	void norm(){
		tipo a = mcd(p,q);
		if(a) p/=a, q/=a;
		else q=1;
		if (q<0) q=-q, p=-p;}
	frac operator+(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
	frac operator-(const frac& o){
		tipo a = mcd(q,o.q);
		return frac(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
	frac operator*(frac o){
		tipo a = mcd(q,o.p), b = mcd(o.q,p);
		return frac((p/b)*(o.p/a), (q/a)*(o.q/b));}
	frac operator/(frac o){
		tipo a = mcd(q,o.q), b = mcd(o.p,p);
		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));}
	bool operator<(const frac &o) const{return p*o.q < o.p*q;}
	bool operator==(frac o){return p==o.p&&q==o.q;}
};

frac convert(frac a, frac b){
    return frac(a.p*b.q,a.q*b.p);
}

void print(frac f){
    cout<<f.p<<'/'<<f.q<<endl;
}
ll power(ll b, ll e) {
	ll r=1;
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}

int main()
{
    FIN;
    // #ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    string input = "";
    while(input != "0"){
        cout<<"Oe, mete un numerio periodico con el formato a.bb|ccc";
        cout<<" (por ejemplo, 1/3 seria 0.|3) o 0 para salir"<<endl;
        cin>>input;
        if(input =="0")break;

        string parteEntera = "";
        ll decNoP = 0;
        string per = "";
        int st = 0;
        fore(i,0,SZ(input)){
            char c = input[i];
            if(c=='.'||c=='|'){
                st++;continue;
            }
            if(st==1)decNoP++;
            if(st<2)parteEntera+=c;
            else per+=c;
        }
        frac x = frac(1,power(10LL,SZ(per)));
        frac sums = convert(x,frac(1,1)-x);
        frac factorComun = sums * frac(stoll(per),1);
        frac sumado = factorComun+frac(stoll(parteEntera),1);
        frac ans = sumado * frac(1,power(10LL,decNoP));
        print(ans);
    }
    return 0;
}
