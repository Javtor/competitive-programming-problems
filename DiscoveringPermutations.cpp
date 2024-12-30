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
   int T;
    int cnt = 0;
    cin >> T;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        string t = s;
        cout<<"Case "<<++cnt<<":\n";
        while(m--)
        {
            cout<<t.substr(0,n)<<endl;
            next_permutation(t.begin(), t.begin() + n);
            if(t == s)
                break;
        }
    }
    return 0;
}
