#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;cin>>n;
    vector<pair<double,double>> vOrig;
    vector<double> v;
    while(n--){
        double v,l;cin>>v>>l;
        vOrig.pb({v,l});
    }
    n=vOrig.size();
    sort(ALL(vOrig));

    fore(i,0,vOrig.size()){
        v.pb(vOrig[i].snd);
    }

    double l = 0, r = 1e9+5;
    if((vOrig[0]).fst==0)l=(vOrig[0]).snd;
    int inter = 35;
    double ans = 0;
    while (inter--)
    {
        double m = l+(r-l)/2;
        bool pos = true;

        double location = 0;
        int ubic = 0;
        
        while(ubic < n && abs(v[ubic]-location)<=m){
            ubic++;
        }

        int ind = min_element(v.begin()+ubic,v.end())-v.begin();
        if(ind<n)
        location = v[ind]+m;

        while(ubic < n && abs(v[ubic]-location)<=m){
            ubic++;
        }
        if(ubic<ind)pos=false;

        ind = min_element(v.begin()+ubic,v.end())-v.begin();
        if(ind<n)
        location = v[ind]+m;

        while(ubic < n && abs(v[ubic]-location)<=m){
            ubic++;
        }
        if(ubic<n)pos=false;

        if(pos){r=m;ans=m;}
        else l=m;
    }
    cout<<fixed<<setprecision(1)<<ans;
    
    return 0;
}
