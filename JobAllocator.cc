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
    bitset<100000+15> bs[8][9]; //i,j tiene j de tipo i
    int mac = 0;
    while(n--){
        char t;cin>>t;
        if(t=='C'){
            mac++;
            int r;cin>>r;
            int res[k];
            mset(res,0);
            fore(i,0,r){
                int aaa;cin>>aaa;aaa--;
                res[aaa]++;
            }
            fore(i,0,k){
                bs[i][res[i]].set(mac);
            }
            fore(i,0,8){
                for(int j=7; j >=0;j--){
                    bs[i][j] |= bs[i][j+1];
                }
            }

        }
        if(t=='J'){
            int r;cin>>r;
            int res[k];
            mset(res,0);
            fore(i,0,r){
                int aaa;cin>>aaa;aaa--;
                res[aaa]++;
            }
            bitset<100000+15> act;
            act.set();
            fore(i,0,k){
                act &= bs[i][res[i]];
            }
            cout<<act.count()<<endl;
        }
        if(t=='D'){
            int id;cin>>id;
            fore(i,0,8)fore(j,0,9){
                bs[i][j].set(id,0);
            }
        }
    }
    
    return 0;
}
