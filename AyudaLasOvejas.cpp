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

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    char past[r][c];
    bool pos = true;
    fore(i, 0, r)
    {
        fore(j, 0, c)
        {
            char car;
            cin >> car;
            if (car == '.')
                car = 'D';
            past[i][j] = car;
        }
    }
    fore(i, 0, r)
    {
        fore(j, 0, c)
        {
            char car = past[i][j];
            if (car == 'S')
            {
                if (i > 0 && past[i - 1][j] == 'W' || j > 0 && past[i][j - 1] == 'W' || i < r - 1 && past[i + 1][j] == 'W' || j < c - 1 && past[i][j + 1] == 'W')
                {
                    pos = false;
                }
            }
        }
    }
    if (!pos)
    {
        cout << "No";
    }
    else
    {
        cout<<"Yes\n";
        fore(i, 0, r)
        {
            fore(j, 0, c)
            {
                char car = past[i][j];
                cout << car;
            }
            cout << "\n";
        }
    }
    return 0;
}
