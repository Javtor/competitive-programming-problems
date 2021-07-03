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
    while(n||m){
        vector<pair<ii,int>> r(m);
        vector<int> a(n);
        vector<int> p(n);
        iota(a.begin(),a.end(),0);
        fore(i,0,m){
            int a,b,c;cin>>a>>b>>c;
            r[i]={{a,b},c};
        }
        ll cnt = 0;
        do{
            fore(i,0,n){
                p[a[i]]=i;
            }
            bool valid = 1;
            fore(i,0,m){
                int a = r[i].fst.fst;
                int b = r[i].fst.snd;
                int c = r[i].snd;
                int d = abs(p[a]-p[b]);
                if((c<0 && d>=abs(c))||(c>0 && d<=abs(c))) valid =1;
                else {valid=0;break;}
                
            }
            if(valid)cnt++;
        } while(next_permutation(a.begin(),a.end()));
        cout<<cnt<<endl;
        cin>>n>>m;
    }
    return 0;
}
