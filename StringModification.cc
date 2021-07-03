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
    freopen("output.txt", "w", stdout);
#endif
string a="a";string aa="aa";
string b ="b";
// bool comp = lexicographical_compare(all(aa),all(aa));
    // cout<<comp;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string mini = s;
        int minK = 1;
        fore(k,2,n+1){
            string gen = "";
            fore(i,k-1,n){
                gen+=s[i];
            }
            if((n-k+1)%2==0){
                fore(i,0,k-1){
                    gen+=s[i];
                }
            } else{
                for(int i = k-2;i>=0;i--){
                    gen+=s[i];
                }
            }
            if(gen<mini){
                mini = gen;minK=k;
            }
        }
        cout<<mini<<"\n";
        cout<<minK<<"\n";
    }
    return 0;
}
