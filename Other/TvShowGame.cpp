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
#define MAXN 2 * 5000 + 12
typedef long long int ll;

using namespace std;

bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;
int neg(int x) { return MAXN - 1 - x; } // (2SAT)
vector<int> g[MAXN];
int n, lw[MAXN], idx[MAXN], qidx, cmp[MAXN], qcmp;
stack<int> st;
void tjn(int u)
{
    lw[u] = idx[u] = ++qidx;
    st.push(u);
    cmp[u] = -2;
    for (int v : g[u])
    {
        if (!idx[v] || cmp[v] == -2)
        {
            if (!idx[v])
                tjn(v);
            lw[u] = min(lw[u], lw[v]);
        }
    }
    if (lw[u] == idx[u])
    {
        int x, l = -1;
        do
        {
            x = st.top();
            st.pop();
            cmp[x] = qcmp;
            if (min(x, neg(x)) < nvar)
                l = x;
        } while (x != u);
        if (l != -1)
            truth[qcmp] = (cmp[neg(l)] < 0); // (2SAT)
        qcmp++;
    }
}
void scc()
{
    memset(idx, 0, sizeof(idx));
    qidx = 0;
    memset(cmp, -1, sizeof(cmp));
    qcmp = 0;
    fore(i, 0, n) if (!idx[i]) tjn(i);
}
// Only for 2SAT:
void addor(int a, int b)
{
    g[neg(a)].pb(b);
    g[neg(b)].pb(a);
}
bool satisf(int _nvar)
{
    nvar = _nvar;
    n = MAXN;
    scc();
    fore(i, 0, nvar) if (cmp[i] == cmp[neg(i)]) return false;
    return true;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k, n;
    cin >> k >> n;
    while (n--)
    {
        int a, c, e;
        char b, d, f;
        cin >> a >> b >> c >> d >> e >> f;
        a--;
        c--;
        e--;
        a = b == 'B' ? a : neg(a);
        c = d == 'B' ? c : neg(c);
        e = f == 'B' ? e : neg(e);
        addor(a,c);
        addor(a,e);
        addor(c,e);
    }
    if(satisf(k)){
        fore(i,0,k){
            cout<<(truth[cmp[i]]?'B':'R');
        }
    } else{
        cout<<-1;
    }
    return 0;
}
