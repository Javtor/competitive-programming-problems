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
typedef long long int ll;
typedef unsigned long long int uint64;

ll poww10[18] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000};

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<ll> classyS;
    classyS.insert(1e18);
    forn(i, 18)
    {
        FOR(j, i + 1, 18, 1)
        {
            FOR(k, j + 1, 18, 1)
            {
                forn(i2, 10)
                {
                    forn(j2, 10)
                    {
                        forn(k2, 10)
                        {
                            classyS.insert(i2 * poww10[i] + j2 * poww10[j] + k2 * poww10[k]);
                        }
                    }
                }
            }
        }
    }
    vector<ll> classy = vector<ll>(all(classyS));
    int t;
    cin >> t;
    while (t--)
    {
        
        ll l, r;
        cin >> l >> r;

        int lI = 0;
        int lR = 0;
        auto it = lower_bound(all(classy), l);
        if (it == classy.end())
        {
            lI = -1;
        }
        else
        {
            std::size_t index = distance(classy.begin(), it);
            lI = index;
            if(*it > r){
                lI = -1;
            }
        }
        if (lI != -1 && *it <= r)
        {

            it = lower_bound(all(classy), r);
            if (it == classy.end())
            {
                lR = -1;
            }
            else
            {
                std::size_t index = distance(classy.begin(), it);
                lR = index;
                if (*it > r)
                {
                    lR--;
                }
                
            }
        }
        // cout << lI <<" "<<lR <<"\n";
        if(lI==-1)
            cout<<0<<"\n";
        else
        cout << lR-lI+1<<"\n";
    }

    return 0;
}