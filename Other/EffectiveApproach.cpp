#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, m, b;

    cin >> n;

    int arr[n+1];

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a] = i+1;
    }

    cin >> m;

    long long int ansa = 0, ansb = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> b;
        ansa += arr[b];
        ansb += (n+1-arr[b]);
    }

    cout << ansa << " " << ansb << endl;
    
    return 0;
}
