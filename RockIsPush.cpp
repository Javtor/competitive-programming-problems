#include <bits/stdc++.h>
#define MODD 1000000007
#define ll long long
using namespace std;

int rocks_right[2222][2222];
int rocks_down[2222][2222];

string S[2222];

ll dp[2222][2222][2];
// dir=0 -> right
// dir=1 -> down

ll Solve(int x, int y, int dir, int n, int m)
{

    if (x == n - 1)
    {
        if (rocks_right[x][y] == 0 && dir == 0)
            return 1;
        else
            return 0;
    }
    if (y == m - 1)
    {
        if (rocks_down[x][y] == 0 && dir == 1)
            return 1;
        else
            return 0;
    }

    if (dp[x][y][dir] != -1)
        return dp[x][y][dir];

    // rocks_right[x][y],
    // rocks_down[x][y].

    // y+1 to m-1
    // m-1-y-rocks_right[x][y]
    long long ans = 0;

    if (dir == 0)
    {
        for (int dy = 1; dy <= m - 1 - y - rocks_right[x][y]; dy++)
        {
            ans += Solve(x, y + dy, 1 - dir, n, m) % MODD;
        }
    }
    else
    {
        // x+1 to n-1
        // n-1-x-rocks_down[x][y]
        for (int dx = 1; dx <= n - 1 - x - rocks_down[x][y]; dx++)
        {
            ans += Solve(x + dx, y, 1 - dir, n, m) % MODD;
        }
    }
    return dp[x][y][dir] = ans % MODD;
}

ll dpc_right[2222][2222][2];
ll dpc_down[2222][2222][2];

ll Solve(int n, int m)
{

    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= m; y++)
            for (int dir = 0; dir <= 1; dir++)
                dpc_right[x][y][dir] = dpc_down[x][y][dir] = 0;

    for (int x = n - 1; x >= 0; x--)
        for (int y = m - 1; y >= 0; y--)
            for (int dir = 0; dir <= 1; dir++)
            {
                if (x == n - 1)
                {
                    dp[x][y][dir] = (rocks_right[x][y] == 0 && dir == 0);
                }
                else if (y == m - 1)
                {
                    dp[x][y][dir] = (rocks_down[x][y] == 0 && dir == 1);
                }
                else
                {
                    long long ans = 0;

                    if (dir == 0)
                    {
                        int max_dy = m - 1 - y - rocks_right[x][y];
                        ans = dpc_right[x][y + 1][1 - dir] - dpc_right[x][y + max_dy + 1][1 - dir];
                    }
                    else
                    {
                        int max_dx = n - 1 - x - rocks_down[x][y];
                        ans = dpc_down[x + 1][y][1 - dir] - dpc_down[x + max_dx + 1][y][1 - dir];
                    }
                    ans %= MODD;
                    ans = (ans + MODD) % MODD;
                    dp[x][y][dir] = ans;
                }

                dpc_right[x][y][dir] = (dpc_right[x][y + 1][dir] + dp[x][y][dir]) % MODD;
                dpc_down[x][y][dir] = (dpc_down[x + 1][y][dir] + dp[x][y][dir]) % MODD;
            }
    return (dp[0][0][0] + dp[0][0][1]) % MODD;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> S[i];

    for (int i = 0; i < n; i++)
    {
        rocks_right[i][m - 1] = 0;
        for (int j = m - 2; j >= 0; j--)
        {
            rocks_right[i][j] = rocks_right[i][j + 1] + (S[i][j + 1] == 'R');
        }
    }

    for (int j = 0; j < m; j++)
    {
        rocks_down[n - 1][j] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            rocks_down[i][j] = rocks_down[i + 1][j] + (S[i + 1][j] == 'R');
        }
    }
    cout << Solve(n,m) << endl;
    //cout << (Solve(0, 0, 0, n, m)%MODD + Solve(0, 0, 1, n, m)%MODD)%MODD << endl;
}