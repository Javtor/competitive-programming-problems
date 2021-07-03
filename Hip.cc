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

const int len = 5;

const double EPS=1e-4;
double reduce(vector<vector<double> >& x){ // returns determinant
	int n=x.size(),m=x[0].size();
	int i=0,j=0;double r=1.;
	while(i<n&&j<m){
		int l=i;
		fore(k,i+1,n)if(abs(x[k][j])>abs(x[l][j]))l=k;
		if(abs(x[l][j])<EPS){j++;r=0.;continue;}
		if(l!=i){r=-r;swap(x[i],x[l]);}
		r*=x[i][j];
		for(int k=m-1;k>=j;k--)x[i][k]/=x[i][j];
		fore(k,0,n){
			if(k==i)continue;
			for(int l=m-1;l>=j;l--)x[k][l]-=x[k][j]*x[i][l];
		}
		i++;j++;
	}
	return r;
}

void print(vector<vector<double> >& x){
    fore(i,0,SZ(x)){
        fore(j,0,SZ(x[i])){
            cout<<x[i][j]<<"";
        }
        cout<<"\n";
    }
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
    int n;cin>>n;
    vector<vector<double>> x(len+n,vector<double>(len*10+1));
    fore(i,0,n){
        string s;cin>>s;
        fore(j,0,s.size()){
            int num = s[j] - '0';
            x[i][j*10 + num] = 1;
        }
        int u;cin>>u;
        x[i][len*10] = u;
    }

    fore(j,0,len){
        fore(k,0,10){

            x[n+j][j*10+k] = 1;
        }
        x[n+j][len*10] = 1;
    }

    reduce(x);
    // x = {{1,2},{3,4}};
    print(x);
    return 0;
}
