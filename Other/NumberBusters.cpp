#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
int am[1010];
ll w;
 
ll get(ll t){
	if(t<0)return 0;
	ll tot=(t/w)*am[w-1];
	tot+=am[t%w];
	return tot;
}
 
 
int main(){FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
	ll a,b,x,c; cin>>a>>b>>w>>x>>c;
	
	fore(t,0,w){
		if(b>=x) b-=x;
		else am[t]=1,b=w-(x-b);
		assert(b>=0);
	}
	
	
	fore(i,0,w)cout<<i<<":" <<am[i]<<"\n";
	fore(i,1,w) am[i]+=am[i-1];
	
	
	
	ll l=0,r=1e15;
	while(l<=r){
		ll m=(l+r)/2;
		if(c-(m)<=a-get(m-1)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}