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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "";
    fore(i, 0, n - 1) ans += "D";
    fore(i, 0, m - 1) ans += "R";
    bool l = false;
    fore(i, 0, n)
    {   
        l =!l;
        fore(j, 0, m - 1)
        {
            ans+=l?"L":"R";
        }
        ans+=i==n-1?"":"U";
    }
    if(ans.length()>2*n*m){
        cout<<-1;
    } else{
        cout<<ans.length()<<"\n";
        cout<<ans;
    }
    return 0;
}
