#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int N = 9;
 
typedef long long int ll;
 
using namespace std;

int n;
pair<double,double> intervals[N];

bool verify(double gap){
    bool posible = false;
    sort(intervals,intervals+n);
    do {
        int i = 1;
        double start = intervals[0].first;
        for(; i < n; i++){
            start = max(start, intervals[i].fst-gap);
            if(!(start>=intervals[i-1].first && start<=intervals[i].second))break;
            double newT = start+gap;
            if((newT<=EPS+intervals[i].second)
            && (newT>=intervals[i].first-EPS)){
                start = newT;
            }else{
                break;
            }
        }
        if(i == n){posible = true; break;}
    } while ( next_permutation(intervals,intervals+n) );
    //cout<<posible<<" lol - \n";
    return posible;
}

int main(){
    FIN;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin>>n;
    int c = 0;
    while(n){
        c++;
        fore(i,0,n){
            int s,e;cin>>s>>e;
            intervals[i] = {s,e};
        }
        double time_g = -1;
        int itr = 0;
        double start = 0;
        double end = 1441;
        while(itr<500){
            double mid = start+(end-start)/2;
            if(verify(mid)){
                time_g = mid;
                start = mid;
            }else{
                end = mid;
            }
            itr++;
        }
        
        int min = (int)floor(time_g); 
        int seg = round((time_g-floor(time_g))*60.0);
        if(seg == 60){
            seg = 0;
            min++;
        }
        cout<<"Case "<<(c)<<": "<<min<<":";
        if(seg<10)cout<<0;
        cout<<seg<<"\n";
        cin>>n;
    }

    return 0;
}

