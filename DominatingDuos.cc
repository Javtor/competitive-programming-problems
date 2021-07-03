#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n;
    cin >> n;
    vector<int> p(n);
    fore(i, 0, n)
    {
        cin >> p[i];
    }
    ll ans = 0;

    stack<int> s;
    fore(i, 0, n)
    {
        while (!s.empty() && s.top() < p[i])
        {
            s.pop();
            ans++;
        }
        s.push(p[i]);
    }

    while (!s.empty())
    {
        s.pop();
    }
    reverse(p.begin(),p.end());
    fore(i, 0, n)
    {
        while (!s.empty() && s.top() < p[i])
        {
            s.pop();
            ans++;
        }
        s.push(p[i]);
    }

    cout << ans<<endl;
    return 0;
}
