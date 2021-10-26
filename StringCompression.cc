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

vi kmppre(string& t){ // r[i]: longest border of t[0,i)
	vi r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

const int MAXN = 1e5;
ll dp[MAXN];

vector<vi> pref;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    mset(dp,-1);
    string s;cin>>s;
    fore(i,0,SZ(s)){
        string sub = s.substr(i,SZ(s)-i);
        pref.pb(kmppre(sub));
    }
    dp[0]=2;
    fore(j,1,SZ(s)){
        ll r = 2+dp[j-1]; 
        fore(i,0,j){
            ll cur = i? dp[(i-1)] : 0;
            ll pval = pref[i][j+1-i];
            int ts = j-i+1;
            int ps = ts%(ts-pval) == 0?(ts-pval):ts;
            int cuantas = ts/(ts-pval);
            int dig = 0;
            while(cuantas){
                cuantas = cuantas/10;dig++;
            }
            cur+=dig+ps;
            r = min(r,cur);
        }
        dp[j]=r;

    }
    cout<<dp[(SZ(s)-1)]<<endl;
    return 0;
}
