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
    freopen("alarm.in", "r", stdin);
    freopen("alarm.out", "w", stdout);
#define endl '\n'
#endif
    vector<int> seg = {6,2,5,5,4,5,6,3,7,6};
    int n;cin>>n;
    fore(hora,0,24){
        fore(minu,0,60){
            int segs = seg[hora/10]+seg[hora%10]+seg[minu/10]+seg[minu%10];
            if(segs==n){
                if(hora<10)cout<<'0';
                cout<<hora;
                cout<<':';
                if(minu<10)cout<<'0';
                cout<<minu;
                cout<<endl;
                exit(0);
            }
        }
    }

    cout<<"Impossible"<<endl;
    return 0;
}
