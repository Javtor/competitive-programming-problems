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

double dp[80][80][80][2];

double solve(int C, int H, int X, int flag, int depth)
{
    double &ans = dp[C][H][X][flag];

    if (ans != -1)
        return ans;
    if (C == 75)
        return ans = 1;
    if (H == 75)
        return ans = 0;
    if (depth > 100)
    {
        return 0;
    }
    double probHold = 0;
    if (flag)
    {
        probHold = solve(C + X, H, 0, 1 - flag, depth + 1);
    }
    else
    {
        probHold = solve(C, H + X, 0, 1 - flag, depth + 1);
    }
    //saca 1
    double fact = (1.0 / 6.0);
    double prob = fact * solve(C, H, 0, 1 - flag, 0);
    // El resto
    fore(i, 1, 7)
    {
        int despues = X + i;
        int aCambiar = flag ? C : H;
        if (aCambiar + despues <= 75)
        {
            double tes = solve(C, H, X + i, flag, depth);
            prob += fact * tes;
        }
        else
        {
            prob += fact * solve(C, H, 0, 1 - flag, 0);
        }
    }

    ans = max(prob, probHold);
    return ans;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    fore(i, 0, 80) fore(j, 0, 80) fore(k, 0, 80) fore(l, 0, 2) dp[i][j][k][l] = -1;

    int Q;
    cin >> Q;
    while (Q--)
    {
        int C, H, X;
        cin >> C >> H >> X;
        double answ = solve(C, H, X, 1, 0);
        cout << answ << endl;
    }
    cout << dp[0][0][0][0];
    return 0;
}
