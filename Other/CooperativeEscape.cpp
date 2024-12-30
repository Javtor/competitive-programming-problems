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

typedef ll tf;
const tf INF = 1e18;
struct MCF
{
    int n;
    vector<tf> prio, curflow, prevedge, prevnode, pot;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    struct edge
    {
        int to, rev;
        tf f, cap, cost;
    };
    vector<vector<edge>> g;
    MCF(int n) : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
    void add_edge(int s, int t, tf cap, tf cost)
    {
        g[s].pb((edge){t, SZ(g[t]), 0, cap, cost});
        g[t].pb((edge){s, SZ(g[s]) - 1, 0, 0, -cost});
    }
    pair<tf, tf> get_flow(int s, int t)
    {
        tf flow = 0, flowcost = 0;
        while (1)
        {
            q.push(s);
            fill(all(prio), INF);
            prio[s] = 0;
            curflow[s] = INF;
            while (!q.empty())
            {
                ll cur = q.top();
                int d = cur >> 32, u = cur;
                q.pop();
                if (d != prio[u])
                    continue;
                for (int i = 0; i < SZ(g[u]); ++i)
                {
                    edge &e = g[u][i];
                    int v = e.to;
                    if (e.cap <= e.f)
                        continue;
                    tf nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio)
                    {
                        prio[v] = nprio;
                        q.push(((ll)nprio << 32) + v);
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == INF)
                break;
            fore(i, 0, n) pot[i] += prio[i];
            tf df = min(curflow[t], INF - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v])
            {
                edge &e = g[prevnode[v]][prevedge[v]];
                e.f += df;
                g[v][e.rev].f -= df;
                flowcost += df * e.cost;
            }
        }
        return {flow, flowcost};
    }
};

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    MCF f(2 * r * c + 2);
    char board[r][c];
    fore(i, 0, r)
    {
        string st;
        cin >> st;
        fore(j, 0, c)
        {
            char ch = st[j];
            board[i][j] = ch;
            f.add_edge(c * i + j + 2, c * i + j + 2 + r * c, ch == 'F' ? 2 : 1, ch == 'F' ? 0 : 1);
            if (i != 0 && board[i - 1][j] != 'x' && ch !='x')
            {
                f.add_edge(c * (i - 1) + j + 2 + r * c, c * i + j + 2, 1, 0);
                f.add_edge(c * i + j + 2 + r * c, c * (i - 1) + j + 2, 1, 0);
            }
            if (j != 0 && board[i][j-1] != 'x' && ch !='x')
            {
                f.add_edge(c * i + (j - 1) + 2 + r * c, c * i + j + 2, 1, 0);
                f.add_edge(c * i + j + 2 + r * c, c * i + (j - 1) + 2, 1, 0);
            }
            if (ch == 'B' || ch == 'C')
            {
                f.add_edge(0, c * i + j + 2, 1, 0);
            }
            if (ch == 'F')
            {
                f.add_edge(c * i + j + 2 + r * c, 1, 2, 0);
            }
        }
    }
    pair<tf, tf> fl = f.get_flow(0, 1);
    if (fl.fst < 2)
    {
        cout << -1;
    }
    else
    {
        cout << fl.snd;
    }
    return 0;
}
