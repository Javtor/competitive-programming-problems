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
#define INF 1000000000
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

const int MAXN = 10;
// int dp[5][5][5][5][5][5][5][5][5][5];
// bool vis[5][5][5][5][5][5][5][5][5][5];
vector<int> comp(MAXN, -1);
int board[6][6];
int type[MAXN]; //2: car, 3: truck
bool pos[MAXN]; //0: hor, 1: ver
int N = 0;

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(type, false, sizeof(type));
    fore(i, 0, 6) fore(j, 0, 6)
    {
        int next;
        cin >> next;
        N = max(N, next);
        board[i][j] = next - 1;
        if (next != 0)
            type[next - 1]++;
    }
    vector<int> estActual(MAXN, 5);
    vector<vector<bool>> ocup(6);
    fore(i, 0, 6) fore(j, 0, 6)
    {
        int th = board[i][j];
        if (th > -1)
        {
            ocup[i].pb(true);

            if ((i != 0 && board[i - 1][j] == th) || (i != 5 && board[i + 1][j] == th))
            {
                estActual[th] = min(estActual[th], i);
                pos[th] = true;
                comp[th] = j;
            }
            else
            {
                estActual[th] = min(estActual[th], j);
                pos[th] = false;
                comp[th] = i;
            }
        }
        else
        {
            ocup[i].pb(false);
        }
    }

    set<vector<int>> visited;
    visited.insert(estActual);

    list<pair<vector<int>, int>> q;

    q.pb({estActual, 0});

    ll ans = 0;

    while (!q.empty())
    {
        pair<vector<int>, int> s = q.front();
        q.pop_front();
        vector<int> a = s.first;
        int depth = s.second;

        if(a[5]== 2 && a[6]==0 && a[0]==4){
            int afasf=0;
        }

        if (depth > 8)
        {
            ans = -1;
            break;
        }
        if ((a[0] == (6 - type[0])))
        { //Si rojo ya esta en el borde, gg
            ans = type[0] + depth;
            break;
        }

        int bActual[6][6];
        memset(bActual, 0, sizeof(bActual));

        fore(i, 0, a.size())
        {
            if (pos[i])
            { //Vert
                fore(j, a[i], a[i] + type[i])
                {
                    bActual[j][comp[i]] = i + 1;
                }
            }
            else
            {
                fore(j, a[i], a[i] + type[i])
                {
                    bActual[comp[i]][j] = i + 1;
                }
            }
        }
        fore(i, 0, N)
        {
           
            bool ocupado = false;
            if (pos[i] && a[i] > 0)
            { //Si es vertical
                ocupado = bActual[a[i] - 1][comp[i]] != 0;
            }
            else if (!pos[i] && a[i] > 0)
            {
                ocupado = bActual[comp[i]][a[i] - 1]  != 0;
            }
            if (a[i] > 0 && !ocupado)
            { //Si puedo moverme para atras
                a[i]--;
                if(visited.find(a)==visited.end()){
                    visited.insert(a);
                    q.pb({a,depth+1});
                }
                a[i]++;
            }

            ocupado = false;
            //Me muevo pa delante:
            if (pos[i] && a[i] < 6 - type[i])
            { //Si es vertical
                ocupado = bActual[a[i] + type[i]][comp[i]];
            }
            else if (!pos[i] && a[i] < 6 - type[i])
            {
                ocupado = bActual[comp[i]][a[i] + type[i]];
            }
            if (a[i] < 6 - type[i] && !ocupado)
            { //Si puedo moverme para adelante
                a[i]++;
                if(visited.find(a)==visited.end()){
                    visited.insert(a);
                    q.pb({a,depth+1});
                }
                a[i]--;
            }
        }
        int asdasdas = 4;
    }

    // ll s = solve(estActual, ocup, 0);
    // if (s > 10)
    //     s = -1;
    cout << ans << "\n";
    return 0;
}