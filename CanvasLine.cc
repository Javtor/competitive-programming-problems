#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(s) ((int) (x).size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int main(){FIN;
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<pair<ll,ll>> inter;
    vector<int> cnt(n,0);
    set<ll> exis;
    vector<ll> nuev;
    vector<pair<ll,int>> shared;

    fore(i,0,n){
        int l, r;cin>>l>>r;
        inter.pb({l,r});
        if(i != 0 && l == inter[i-1].snd){
            shared.pb({l,i-1});
        }
    }
    int p; cin >> p;
    while(p--){
        ll ne; cin >> ne;
        fore(i,0,n){
            if(ne >= inter[i].fst && ne <=inter[i].snd){
                cnt[i]++;
                exis.insert(ne);
                
            }
        }

    }
    fore(i,0,shared.size()){
        ll pl = shared[i].fst;
        int i1 = shared[i].snd;
        int i2 = i1+1;

        if(exis.find(pl) == exis.end() && cnt[i1]<2 && cnt[i2]<2){
            exis.insert(pl);
            nuev.pb(pl);
            cnt[i1]++;cnt[i2]++;
        }
    }

    fore(i,0,n){
        int l = inter[i].fst;
        int r = inter[i].snd;
        if(cnt[i] < 2){
            fore(j,l+1,r-1){
                if(exis.find(j) == exis.end()){
                    exis.insert(j);
                    cnt[i]++;
                    nuev.pb(j);
                    if(cnt[i] == 2)
                        break;
                }
            }
        }
    }
    bool pos = true;
    fore(i,0,n){
        pos = pos && cnt[i]==2;
    }
    if(pos){
        cout<<nuev.size()<<"\n";
        fore(i,0,nuev.size()){
            if(i != 0)  cout<<" ";
            cout<<nuev[i];
        }
        cout<<"\n";
    } else{
        cout<<"impossible\n";
    }
    return 0;
}