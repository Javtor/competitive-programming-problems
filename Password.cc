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

vector<int> z_function(string &s)
{
    int l = 0, r = 0, n = s.size();
    vector<int> z(s.size(), 0); // z[i] = max k: s[0,k) == s[i,i+k)
    fore(i, 1, n)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
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
    string ans = "Just a legend";
    string s;
    cin >> s;
    vector<int> cnt(s.size());
    vector<int> z = z_function(s);
    for (auto i : z)
    {
        cnt[i]++;
    }
    for(int i = s.size()-1;i>0;i--){
        cnt[i-1]+=cnt[i];
    }
    fore(i, 1, s.size())
    {
        if (z[i] == s.size() - i && cnt[s.size() - i] > 1)
        {
            ans = s.substr(0, s.size() - i);
            break;
        }
    }
    cout << ans;
    return 0;
}
