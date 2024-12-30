#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

bool is_lucky(string s){
    for(char c : s) if(c != '4' && c != '7') return false;    
    return true;
}

void solve(){
    string s;
    cin >> s;
    int sum = 0;
    for(char c : s) if(c == '4' || c == '7') sum++;
    if(is_lucky(to_string(sum))) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}
