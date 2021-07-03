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
struct state
{
    int len, link;
    map<char, int> next;
}; //clear next!!
state st[4 * 100005];
int sz, last;
void sa_init()
{
    last = st[0].len = 0;
    sz = 1;
    st[0].link = -1;
}
void sa_extend(char c)
{
    int k = sz++, p;
    st[k].len = st[last].len + 1;
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
        st[p].next[c] = k;
    if (p == -1)
        st[k].link = 0;
    else
    {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[k].link = q;
        else
        {
            int w = sz++;
            st[w].len = st[p].len + 1;
            st[w].next = st[q].next;
            st[w].link = st[q].link;
            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = w;
            st[q].link = st[k].link = w;
        }
    }
    last = k;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string c;
    cin >> c;
    sa_init();
    fore(i, 0, c.length())
    {
        sa_extend(c[i]);
    }
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        state actual = st[0];
        bool pos = true;
        ll count = 1;
        fore(i, 0, s.length())
        {
            char car = s[i];
            if (st[0].next.find(car) == st[0].next.end())
            {
                count = -1;
                break;
            }
            if (actual.next.find(car) != actual.next.end())
            {
                actual = st[actual.next[car]];
            } else{
                count++;
                actual = st[st[0].next[car]];
            }
        }
        cout << count << "\n";
    }
    return 0;
}
