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
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int MAXN = 10005;
int n;
ll k; vi arr(MAXN);

bool cmp(const ll& a, const ll& b) {
	int absa = abs(a), absb = abs(b);
	if (absa != absb) 
        return absa > absb;
	else return a > b;
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
    cin>>n>>k;
    while(n&&k){
        arr.resize(n);
        fore(i,0,n)cin>>arr[i];
        sort(ALL(arr));
        ll sum = 0;

        ll primk = 0;
        sort(ALL(arr));
        reverse(ALL(arr));
        fore(i,0,k)primk+=arr[i];
        
        sort(ALL(arr),cmp);
 
        int cntn=0, zero =0;
        int pos=0, neg=0;
        fore(i,0,k){
            if(arr[i]==0)zero=1;
            else if(arr[i]>0)pos=arr[i];
            else{
                neg=arr[i];cntn++;
            }
            sum+=arr[i];
        }
        if(zero)sum=primk;
        else if(cntn&1 && k<n){
            int primerp = 0, primern = 0, hayz = 0;
            fore(i,k,n)if(arr[i]==0){hayz=1;break;}
            fore(i,k,n)if(arr[i]>0){primerp=arr[i];break;}
            fore(i,k,n)if(arr[i]<0){primern=arr[i];break;}
            if(!pos){
                if(primerp) sum+=-neg+primerp;
                else sum=primk;
            }else{
                if(!primerp && !primern)sum=primk;
                else if(!primerp)sum=sum-pos+primern;
                else if(!primern)sum=sum-neg+primerp;
                else if(pos*primerp>=neg*primern)sum+=-neg+primerp;
                else sum+=-pos+primern;
            }
        }
        cout<<sum<<endl;
        cin>>n>>k;
    }
    return 0;
}
