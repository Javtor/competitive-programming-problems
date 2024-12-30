#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a, b) memset(a, b, sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define sz(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

set<string> todosString;
vector<int> movs;
vector<string> movsBase =
    {
        "abc",
        "defg",
        "hijkl",
        "mnop",
        "qrs",
        "hmq",
        "dinr",
        "aejos",
        "bfkp",
        "cgl",
        "adh",
        "beim",
        "cfjnq",
        "gkor",
        "lps"};

void procesarCadena(string s)
{
    int n = sz(s);
    fore(i, 0, n)
    {
        fore(j, 1, n-i+1)
        {
            string nuev = s.substr(i, j);
            todosString.insert(nuev);
        }
    }
}

void convertirAMov(string s){
    int msk = 0;
    fore(i,0,sz(s)){
        msk|=(1<<(s[i]-'a'));
    }
    movs.pb(msk);
}

vector<int> dp((1<<19)+15,-1);

int go(int msk){
    if(msk==0)return 0;
    int &r = dp[msk];
    if(r!=-1)return r;
    r = 0;
    for(int mv : movs){
        if((msk&mv)==mv){
            int sig = go(msk^mv);
            if(sig==0) r = 1;
        }
    }
    return r;
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
    fore(i,0,sz(movsBase))procesarCadena(movsBase[i]);
    for(auto s:todosString)convertirAMov(s);
    int msk = 0;
    fore(i,0,19){
        char c;cin>>c;
        if(c=='O')msk|=(1<<i);
    }
    cout<<(go(msk)?"Karlsson":"Lillebror");
    return 0;
}
