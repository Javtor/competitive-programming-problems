#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<double,double> cord;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("joy.in", "r", stdin);
    freopen("joy.out", "w", stdout);
#define endl '\n'
#endif
    cord s,f;
    cout<<fixed<<setprecision(10);
    double x1,y1;cin>>x1>>y1;s = {x1,y1};
    cin>>x1>>y1;f = {x1,y1};
    double n,k,vmax;cin>>n>>k>>vmax;
    vector<pair<int,cord>> wind(n+1);
    fore(i,0,n){
        int t;cin>>t;
        double x,y;cin>>x>>y;
        wind[i] = {t, {x,y}};
    }
    wind[n] = {k,{0,0}};
    cord ff = s;
    fore(i,0,n){
        int dist = -wind[i].first+wind[i+1].first;
        ff = {ff.first+(dist*wind[i].second.first),ff.second+(dist*wind[i].second.second)};
    }
    //cout<<ff.first<<" "<<ff.second<<"\n";
    cord dist = {f.first-ff.first,f.second-ff.second};
    cord ajus = {dist.fst/k,dist.snd/k};
    if(dist.fst*dist.fst+dist.snd*dist.snd<=vmax*k*vmax*k){
        cout<<"Yes\n";
        cord act = s;
        fore(i,0,n){
            int d = -wind[i].first+wind[i+1].first;
            fore(j,0,d){
                act = {act.first+(wind[i].second.first+dist.first/k) , act.second+(wind[i].second.second+dist.second/k)};
                cout<<act.first<<" "<<act.second<<"\n";
            }  
        }
    }else{
        cout<<"No\n";
    }
    return 0;
}
