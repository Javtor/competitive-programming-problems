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

#define CLASSNAME EllysPronunciation
#define METHODNAME getGood
class CLASSNAME{public:
  int METHODNAME(vector <string> words) {
    // int res=0;
    vector<char> vowels = {'a','e','i','o','u'};
        int ans = 0;
    for(string w : words){
        int cnt = 0;
        fore(i,0,SZ(w)){
            if(*lower_bound(ALL(vowels),w[i])==w[i])cnt++;
            else cnt--;
        }
        if(cnt==0)ans++;
    }
    return ans;
  }
};

// int main()
// {
//     FIN;
// #ifdef LOCAL
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #else
// #define endl '\n'
// #endif
//     CLASSNAME sumarDos;
//     // int n;cin>>n;

//     cout<<sumarDos.METHODNAME({"schornsteinfeger", "schmetterling", "lohnsteuerabzugsbescheinigung", "shifffahrt",
//  "deutsch", "ist", "die", "schoenste", "sprache", "auf", "der", "welt"});
//     return 0;
// }
