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

struct server
{
    ll a;
    ll l;
    int ind;
};

bool menorque(server &a, server &b)
{
    return a.a > b.a;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    ll m;
    cin >> n >> m;
    vector<server> servers;
    fore(i, 0, n)
    {
        ll a;
        int l;
        cin >> a >> l;
        server s;
        s.a = a;
        if (l == 0)
            s.l = 1;
        else
            s.l = 0;
        s.ind = i + 1;
        servers.push_back(s);
    }
    ll sumaTotal = 0;
    sort(all(servers), menorque);
    vector<server> usados;
    int w = 0;
    for (int i = 0; i < servers.size() && sumaTotal < m; i++)
    {
        server next = servers[i];
        sumaTotal += next.a;
        usados.pb(next);
        if (next.l == 0L)
            w++;
    }
    int r = usados.size();
    vector<int> mancosUsados;
    vector<server> prosPorUsar;
    fore(i, 0, r)
    {
        if (usados[i].l==1L)
        {
            mancosUsados.pb(i);
        }
    }
    fore(i, r, n)
    {
        server esteSer = servers[i];
        if (esteSer.l == 0L)
        {
            prosPorUsar.pb(servers[i]);
        }
    }
    vector<server> prosCambiados;
    int i = 0;
    int mancosUsadosSize=(int)(mancosUsados.size());
    while (mancosUsadosSize - 1 - i >= 0 && i < prosPorUsar.size())
    {
        int nextInd = mancosUsados[mancosUsadosSize - 1 - i];
        server manco = usados[nextInd];
        server pro = prosPorUsar[i];
        if (sumaTotal - manco.a + pro.a >= m)
        {
            usados[mancosUsados[mancosUsadosSize - 1 - i]] = pro;
            w++;
        }
        i++;
        // cout<<i<<endl;
    }
    cout << r << " " << w << "\n";
    fore(i, 0, r)
    {
        cout << usados[i].ind << " ";
    }

    return 0;
}