#include <bits/stdc++.h>

using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define forn(i, n) for (int i = 0; i < n; i++)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rforn(i, n) for (int i = n; i >= 0; i--)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int64 n, p;

    cin >> n >> p;

    bool si = false;

    int64 nClone2 = n;

    forn(i, 1000000)
    {
        int64 ind = i + 1;
        int64 nClone = max(0LL, n - (p * ind));
        int64 nClone2 = max(0LL, n - (p * ind));

        int bits = 0;
        while (nClone2)
        {
            nClone2 &= nClone2 - 1;
            bits++;
        }

        if (bits > ind)
        {
            continue;
        }
        else if (bits <= ind)
        {
            si = true;
            cout << ind << endl;
            break;
        }
        else
        {
            string s = bitset<64>(nClone).to_string();
            bool encontre = false;
            forn(j, s.size())
            {
                if (s[j] == '1')
                {
                    bits += (1 << (s.size() - 1 - j)) - 1;
                }
                if(bits >= ind){
                    encontre = true;
                    break;
                }
            }
            if (encontre)
            {
                si = true;
                cout << ind << endl;
                break;
            }
        }
    }

    if (!si)
    {
        cout << -1 << endl;
    }

    return 0;
}