#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
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
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    vector<int> vac(53,0);
    vac[a]=1;vac[b]=1;vac[c]=1;vac[d]=1;

    for(int i = 51; i >= 0; i--){
        vac[i]=vac[i]+vac[i+1];
    }

    double xd = 1e9;

    string ans = "";

    fore(i,1,50) fore(j,i+1,51) fore(k,j+1,52) fore(l,k+1,53){
        double pagoPrev = (double)(52-vac[i])/52.0;
        double pagoAct = pagoPrev;
        if(j != i+1){
            pagoPrev = (double)(52-vac[j]-1)/52.0;
        } 
        pagoAct +=pagoPrev;
        if(k != j+1){
            pagoPrev = (double)(52-vac[k]-2)/52.0;
        } 
        pagoAct +=pagoPrev;
        if(l != k+1){
            pagoPrev = (double)(52-vac[l]-3)/52.0;
        } 
        pagoAct +=pagoPrev;
        if(pagoAct<xd){
            xd=pagoAct;
            ans = to_string(i)+" "+to_string(j)+" "+to_string(k)+" "+to_string(l);
        }
    }
    cout<<ans;
    return 0;
}
