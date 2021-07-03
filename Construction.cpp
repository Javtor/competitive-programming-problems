#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define pb push_back
#define fst first
#define snd second
#define ALL(cont) cont.begin(), cont.end()
#define mset(a,b) memset(a,b,sizeof(a));
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
auto rnd=bind(uniform_int_distribution<long long>(0,1), mt19937(time(0)));

ll spiralPrint(int m, int n, vector<int> perm) 
{ 
    int a[m][n];
    mset(a,0);
    int i, k = 0, l = 0; 
    int r = m;int c = n; 
    ll sum = 0;
    int nxt = 0;
  
    while (k < m && l < n) { 
        for (i = l; i < n; ++i) { 
            a[k][i] = perm[nxt++];
            //cout << a[k][i] << " "; 

            int am = a[k][i];
            if(k==0) sum+=am;
            else if(a[k-1][i]!= 0){
                sum+=abs(am-a[k-1][i]);
            }
            if(k==r-1) sum+=am;
            else if(a[k+1][i]!= 0){
                sum+=abs(am-a[k+1][i]);
            }

            if(i==0) sum+=am;
            else if(a[k][i-1]!= 0){
                sum+=abs(am-a[k][i-1]);
            }
            if(i==c-1) sum+=am;
            else if(a[k][i+1]!= 0){
                sum+=abs(am-a[k][i+1]);
            }
        } 
        k++; 
  
        for (i = k; i < m; ++i) { 
            a[i][n-1] = perm[nxt++];
            //cout << a[i][n - 1] << " "; 

            int am = a[i][n - 1];
            if(i==0) sum+=am;
            else if(a[i-1][n-1]!= 0){
                sum+=abs(am-a[i-1][n-1]);
            }
            if(i==r-1) sum+=am;
            else if(a[i+1][n-1]!= 0){
                sum+=abs(am-a[i+1][n-1]);
            }

            if(n-1==0) sum+=am;
            else if(a[i][n-2]!= 0){
                sum+=abs(am-a[i][n-2]);
            }
            if(n-1==c-1) sum+=am;
            else if(a[i][n]!= 0){
                sum+=abs(am-a[i][n]);
            }
        } 
        n--; 

        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                a[m-1][i] = perm[nxt++];
                //cout << a[m - 1][i] << " "; 

                int am = a[m-1][i];
                if(m-1==0) sum+=am;
                else if(a[m-1-1][i]!= 0){
                    sum+=abs(am-a[m-1-1][i]);
                }
                if(m-1==r-1) sum+=am;
                else if(a[m-1+1][i]!= 0){
                    sum+=abs(am-a[m-1+1][i]);
                }

                if(i==0) sum+=am;
                else if(a[m-1][i-1]!= 0){
                    sum+=abs(am-a[m-1][i-1]);
                }
                if(i==c-1) sum+=am;
                else if(a[m-1][i+1]!= 0){
                    sum+=abs(am-a[m-1][i+1]);
                }
            } 
            m--; 
        } 

        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                a[i][l] = perm[nxt++];
                //cout << a[i][l] << " "; 
             
                int am = a[i][l];
                if(i==0) sum+=am;
                else if(a[i-1][l]!= 0){
                    sum+=abs(am-a[i-1][l]);
                }
                if(i==r-1) sum+=am;
                else if(a[i+1][l]!= 0){
                    sum+=abs(am-a[i+1][l]);
                }

                if(l==0) sum+=am;
                else if(a[i][l-1]!= 0){
                    sum+=abs(am-a[i][l-1]);
                }
                if(l==c-1) sum+=am;
                else if(a[i][l+1]!= 0){
                    sum+=abs(am-a[i][l+1]);
                }
            }
            l++; 
        } 
    } 
    //cout<<'\n';
    return sum;
} 

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    srand((unsigned)time(0));
    vector<int> perm;
    int n,m;cin>>n>>m;
    fore(i,0,n)fore(j,0,m){
        int a;cin>>a;
        perm.pb(a);
    }
    ll mini = 1e18;
    sort(ALL(perm));
    int times = 1000;
    do{
    mini=min(mini,min(spiralPrint(m,n,perm),spiralPrint(n,m,perm)));

    } while (next_permutation(ALL(perm)) && times--);
 
    cout<<mini;
    return 0;
}
