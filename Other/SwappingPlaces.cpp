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
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
auto rnd = bind(uniform_int_distribution<long long>(0, 1), mt19937(time(0)));

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int S, L, N;
    cin >> S >> L >> N;
    vector<string> sig;
    fore(i, 0, S)
    {
        string s;
        cin >> s;
        sig.pb(s);
    }
    map<string, int> mp;
    sort(ALL(sig));
    fore(i, 0, S)
    {
        mp[sig[i]] = i;
    }
    bool conm[S][S];
    mset(conm, 0);
    fore(i, 0, L)
    {
        string s1, s2;
        cin >> s1 >> s2;
        conm[mp[s1]][mp[s2]] = 1;
        conm[mp[s2]][mp[s1]] = 1;
    }
    vector<int> w(N);
    fore(i, 0, N)
    {
        string s;
        cin >> s;
        w[i] = mp[s];
    }

    vector<int> wFinal;
    vector<int> pref(S, 0);
    while (wFinal.size() < w.size())
    {
        int toAp = -1;
        fore(i, 0, S)
        {
            if (toAp != -1)
            {
                break;
            }
            fore(j, pref[i], N)
            {
                if (w[j] == -1 || conm[i][w[j]])
                {
                    pref[i]++;
                }
                else if (i == w[j])
                {
                    toAp = i;
                    w[j]=-1;
                    break;
                }else{
                    break;
                }
            }
        }
        wFinal.pb(toAp);
    }
    fore(i,0,wFinal.size()){
        cout<<sig[wFinal[i]]<<' ';
    }
    return 0;
}
