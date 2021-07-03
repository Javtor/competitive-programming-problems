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
struct star
{
    int ind, x, y, b;
};
bool sortbysec(const pair<double, int> &a,
               const pair<double, int> &b)
{
    if (abs(a.first -b.first)>EPS)
        return a.first<b.first;
    else
        return (a.second > b.second);
}
int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    star stars[N];
    fore(i, 0, N)
    {
        int X, Y, B;
        cin >> X >> Y >> B;
        star st;
        st.ind = i;
        st.x = X;
        st.y = Y;
        st.b = B;
        stars[i] = st;
    }

    vector<pair<double, int>> intervals;
    int necount = 0;
    fore(i, 0, N) fore(j, i + 1, N)
    {
        star S = stars[i];
        star T = stars[j];
        necount++;
        if (S.b != T.b)
        {

            if (S.b < T.b)
                swap(S, T);
            int y2 = S.y - T.y;
            int x2 = S.x - T.x;

            double angle = atan2(y2, x2);
            if (angle < 0)
            {
                intervals.pb(mp(-angle, 1));
                intervals.pb(mp(-angle + PI, -1));
            }
            else
            {
                intervals.pb(mp(0, 1));
                intervals.pb(mp(PI - angle, -1));
                if (angle != 0)
                {
                    intervals.pb(mp(2 * PI - angle, 1));
                }
            }
        }
        else
        {
            intervals.pb({0, 1});
        }
    }
    // cout << necount << "\n";
    sort(all(intervals),sortbysec);
    char ans = 'N';
    int cnt = 0;
    fore(i, 0, intervals.size())
    {
        // cout << intervals[i].first << " - " << intervals[i].second << "\n";
        cnt += intervals[i].second;
        if (cnt == necount)
        {
            // cout << intervals[i].first << "\n";
            ans = 'Y';
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
