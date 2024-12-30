#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
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

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;

    int cuantosIzq = total / 2;

    int l = 0, r = n;
    while (l <= r)
    {
        int cuantosN1 = l + (r - l) / 2;

        double maxL = -1e10;
        double minR = 1e10;
        double minR2 = 1e10;
        if (cuantosN1 > 0)
        {
            maxL = nums1[cuantosN1 - 1];
        }
        if (cuantosN1 < n)
        {
            minR = nums1[cuantosN1];
        }
        int meFaltan = cuantosIzq - cuantosN1;
        if (meFaltan < 0)
        {
            r = cuantosN1 - 1;
        }
        else if (meFaltan > m)
        {
            l = cuantosN1 + 1;
        }
        else
        {
            if (meFaltan < m)
            {
                minR2 = min(minR2, (double)nums2[meFaltan]);
            }
            if (meFaltan != 0)
            {
                maxL = max(maxL, (double)nums2[meFaltan - 1]);
            }

            if (maxL <= min(minR, minR2))
            {
                double median = min(minR, minR2);
                if (total % 2 == 0)
                {
                    median /= 2.0;
                    median += maxL / 2.0;
                }
                return median;
            }
            else if (minR > maxL)
            {
                r = cuantosN1 - 1;
            }
            else
            {
                l = cuantosN1 + 1;
            }
        }
    }
    return 0;
}

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);

    fore(i, 0, n)
    {
        cin >> nums1[i];
    }
    fore(i, 0, m)
    {
        cin >> nums2[i];
    }

    cout<<findMedianSortedArrays(nums1,nums2);
    return 0;
}