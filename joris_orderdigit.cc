/*
 * Solution to Multiplying Digits
 *
 * The following optimizations are used:
 *   ORDERDIGIT - sequence of digits must be non-decreasing
 *
 * The following optimizations are not used:
 *   PREPDIV    - prepare a list of divisors of N
 *   HASHMAP    - use C++ unordered_map instead of map
 *   CONCAT     - build numbers up to half length, then glue them together
 *   
 * This program is probably still fast enough.
 */

#undef  OPT_PREPDIV
#undef  OPT_HASHMAP
#undef  OPT_CONCAT
#define OPT_ORDERDIGIT


#include <cstdio>
#include <cassert>
#include <cerrno>
#include <cstdint>
#ifdef OPT_HASHMAP
#include <unordered_map>
#else
#include <map>
#endif
#include <queue>

using namespace std;

typedef uint_fast64_t Num;
static const uint_fast64_t MAXNUM = (1ULL << 63) - 1;


/* Solve problem. */
Num solve(unsigned int b, Num n)
{
    // Special case for B < N: just use that one digit.
    if (n < b) {
        return n;
    }

    vector<unsigned int> divisors;
    for (unsigned int k = b - 1; k >= 2; k--) {
        if (n % k == 0) {
            divisors.push_back(k);
        }
    }


    // Check whether a solution is possible.
    {
        Num t = n;

        for (unsigned int k = b - 1; k >= 2; k--) {

            while (t % k == 0) {
                t /= k;
            }
        }
        if (t > 1) {
            // N has a prime factor >= B. No solution possible.
            return 0;
        }
    }

    // Keep track of the best solution so far.
    Num best_solution = 0;

    // Build up map[t] = smallest x such that f(x) == t.
    map<Num,Num> map;

    // Queue of new elements in map.
    queue<Num> q;

    // Start with the single-digit divisors of N.

    for (unsigned int k = b - 1; k >= 2; k--) {
        if (n % k != 0) continue;
        map[k] = k;
        q.push(k);
    }

    // The map contains an optimal solution for all cases that require
    // at most used_digits digits.
    int used_digits = 1;
    Num digits_base = b;

    // Push marker before we start adding a new digit.
    q.push(0);

    // Expand knowledge.
    while (1) {

        assert(!q.empty());
        Num t = q.front();
        q.pop();

        if (t == 0) {

            if (map.count(n) > 0) {
                // Found solution.
                return map[n];
            }

            q.push(0);

        } else {

            Num tt = map[t];
            Num u = n / t;

            // Construct new numbers by appending a digit to tt.
            unsigned int lastd = tt % b;

            for (unsigned int k : divisors) {
                if (k < lastd) {
                    break;
                }
                if (u % k == 0 ) {
                    Num s = t * k;
                    Num ss = tt * b + k;
                    auto& p = map[s];
                    if (p == 0) {
                        p = ss;
                        q.push(s);
                    } else if (ss < p) {
                        p = ss;
                    }
                }
            }
        }
    }

    // We must have seen the optimal answer by now.
    assert(best_solution > 0);
    return best_solution;
}


/* Main program. */
int main(void)
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    // Read input.
    char buf[80];
    char *p = fgets(buf, sizeof(buf), stdin);
    assert(p);

    // Check end of file.
    int rc = fgetc(stdin);
    assert(rc == EOF);

    // Parse input.
    assert(buf[0] >= '0' && buf[0] <= '9');
    errno = 0;
    long b = strtol(buf, &p, 10);
    assert(errno == 0);
    assert(p[0] == ' ');
    p++;
    assert(p[0] >= '0' && p[0] <= '9');
    long long n = strtoll(p, &p, 10);
    assert(errno == 0);
    assert(p[0] == '\n');

    // Check input.
    assert(b > 2 && b <= 10000);
    assert(n > 0 && n <= (long long)MAXNUM);

    // Solve problem.
    long long ans = solve(b, n);

    // Write output.
    if (ans > 0) {
        printf("%lld\n", ans);
    } else {
        printf("impossible\n");
    }

    return 0;
}

// end
