#include <bits/stdc++.h>
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

const int N = 100010;

typedef long long int ll;

using namespace std;

map<int, int> ids;
set<int> graph[N];
int heightC[N];
bool visited[N];
bool done[N];
ll cycle;
void createComps(int origin, int pos, int height)
{
    if (visited[pos])
    {
        return;
    }
    visited[pos] = true;
    heightC[pos] = height;
    for (auto elem : graph[pos])
    {
        if (!visited[elem])
        {
            createComps(pos, elem, height + 1);
        }
        else if (elem != origin && !done[elem])
        {
            cycle = height - heightC[elem] + 1;
        }
    }
    done[pos] = true;
}

int main()
{
    FIN;
    int n, c;
    cin >> n >> c;
    while (n)
    {
        bool posible = true;
        fore(i,0,N){
            graph[i].clear();
        }
        memset(heightC,0,sizeof(heightC));
        memset(visited,0,sizeof(visited));
        memset(done,0,sizeof(done));
        ids.clear();

        set<int> used;
        int cnt = 0;
        fore(i, 0, c)
        {
            int c1, c2;
            cin >> c1 >> c2;

            if (ids.find(c1) == ids.end())
                ids[c1] = cnt++;
            if (ids.find(c2) == ids.end())
                ids[c2] = cnt++;

            int u = ids[c1];
            int v = ids[c2];
            used.insert(u);
            used.insert(v);

            graph[u].insert(v);
            graph[v].insert(u);
            if (graph[u].size() > 2 || graph[v].size() > 2)
            {
                posible = false;
            }
        }
        cycle = -1;
        for (int elem : used)
        {
            if (!visited[elem])
            {
                createComps(-1, elem, 0);
            }
        }
        if (cycle != -1 && cycle != n)
        {
            posible = false;
        }

        if (posible)
        {
            cout << "Y";
        }
        else
        {
            cout << "N";
        }
        cin >> n >> c;

        cout << "\n";
    }

    return 0;
}