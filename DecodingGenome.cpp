#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;

using namespace std;
vector<vector<int>> graph;


vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> mul(n);
    for (int i = 0; i < n; i++)
    {
        mul[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
}

int main(){FIN;
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int n;cin>>n;
    cout<<2*n<<endl;
	return 0;
}
