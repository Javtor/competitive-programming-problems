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

int numbers;
int dp[4000004];
bool binaryRepresent[1000005][23];

int find(int pos)
{
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    VI toCheck;
    bool start = false;

    for (int i = 0; i < 23; i++)
    {
        if (binaryRepresent[pos][i])
        {
            if (!start)
            {
                for (int j = 0; j < numbers; j++)
                {
                    if (!binaryRepresent[j][i])
                    {
                        toCheck.PB(j);
                    }
                }
                start = true;
            }
            else
            {
                VI reference;
                for (int j = 0; j < toCheck.size(); j++)
                {
                    if (!binaryRepresent[toCheck[j]][i])
                    {
                        reference.PB(toCheck[j]);
                    }
                }
                toCheck = reference;
            }
        }
    }
    if (toCheck.size() != 0)
    {
        dp[pos] = toCheck[0];
        for (int i = 0; i < toCheck.size(); i++)
        {
            dp[toCheck[i]] = pos;
        }
        return dp[pos];
    }
    else
    {
        dp[pos] = -2;
        return -2;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> numbers;
    int numb[numbers];
    MEM(dp, -1);
    VI lol;
    //		for (int i = 0; i < number; i++) {
    //			lol.add();
    //		}
    for (int i = 0; i < numbers; i++)
    {
        int num;
        cin >> num;
        string val = bitset<23>(num).to_string();
        numb[i] = num;
        for (int j = val.length() - 1; j >= 0; j--)
        {
            if (val[j] == '1')
                binaryRepresent[i][val.length() - 1 - j] = true;
        }
    }

    for (int i = 0; i < numbers; i++)
    {
        int sol = find(i);
        if (i != 0)
            cout << " ";
        if (sol != -2)
        {
            cout << numb[sol];
        }
        else
        {
            cout << -1;
        }
    }
    cout << ("\n");

    return 0;
}