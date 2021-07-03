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
const int MAXN = 16+10;
int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
// void manacher(const string& s){
// 	int l=0,r=-1,n=s.size();
// 	fore(i,0,n){
// 		int k=i>r?1:min(d1[l+r-i],r-i);
// 		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
// 		d1[i]=k--;
// 		if(i+k>r)l=i-k,r=i+k;
// 	}
// 	l=0;r=-1;
// 	fore(i,0,n){
// 		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
// 		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
// 		d2[i]=--k;
// 		if(i+k-1>r)l=i-k,r=i+k-1;
// 	}
// }

ll ans;
void process(const string& s){
    if(s.empty())
        return;
    
    int l=0,r=-1,n=s.size();
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}

    int mp=0, mi=0;
    fore(i,0,sz(s)){
        if(d2[i]>d2[mi]){mp = d2[i];mi=i;}
    }
    ans+=sz(s)-(2*mp);
    if(mp>0)ans++;
    string nuevo(s.substr(mi-mp,mp));
    process(nuevo);
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
    int t;cin>>t;
    while(t--){
        ans=0;string s;cin>>s;
        process(s);
        cout<<ans<<endl;
    }
    return 0;
}
