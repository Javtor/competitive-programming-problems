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

int main()
{
    FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n,k;cin>>n>>k;
    vector<int> stud;
    fore(i,0,n){
        int cur = 0;
        fore(j,0,k){
            char c;cin>>c;
            cur+=(c=='T');
            cur = cur<<1;
        }
        cur = cur>>1;
        stud.pb(cur);
    }
    int mayor = 0;
    fore(i,0,1<<k){
        int menor = 1e8;
        for(int st : stud){
            int tst = ~(st^i);
            int score = 0;
            fore(i,0,k){
                score += (tst>>i)&1;
            }
            menor = min(menor,score);
        }
        mayor = max(mayor,menor);
    }
    cout<<mayor<<endl;
    return 0;
}
