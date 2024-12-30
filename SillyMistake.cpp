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
//    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    set<int> setD;
    set<int> setDay;
    int days = 0;
    bool possible = true;
    vector<int> vec;
    while (n--)
    {
        int d;
        cin >> d;

        if (d > 0)
        {
            if (setD.find(d) != setD.end() || setDay.find(d) != setDay.end())
            {
                possible = false;
                break;
            }
            else
            {
                setD.insert(d);
                setDay.insert(d);
            }
        }
        else
        {
            d = abs(d);
            if (setD.empty() || setD.find(d) == setD.end())
            {
                possible = false;
                break;
            }
            else
            {
                setD.erase(d);
            }
        }
        days++;
        if (days != 1)
        {
            if (setD.empty())
            {
                vec.pb(days);
                setDay.clear();
            }
        }
    }
    if (!setD.empty())
    {
        possible = false;
    }
    if (!possible)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << vec.size() << "\n";
        bool first = true;
        fore(i, 0, vec.size())
        {
            if(!first){
                cout << " ";
            }
            first = false;
            int a = vec[i];
            if(i != 0){
                a-=vec[i-1];
            }
            cout << a;
        }
        cout << "\n";
    }
    return 0;
}
