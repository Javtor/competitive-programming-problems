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
    if(n==1)cout<<1;
    else if(n==4)cout<<"3 1 4 2";
    else if(n<5)cout<<"NO SOLUTION";
    else{
        string iz,de;
        int cual =1;
        fore(i,1,n+1){
            if(cual)iz+=to_string(i)+' ';
            else de+=to_string(i)+' ';
            cual = 1-cual;
        }
        cout<<iz<<de;
    }
    return 0;
}
