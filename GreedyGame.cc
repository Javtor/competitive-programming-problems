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

void solve(){
    int n;cin>>n;
    int arr1[n];
    int arr2[n];
    priority_queue<pair<int,int>> pq1;
    
    fore(i,0,n){cin>>arr1[i];}
    
    fore(i,0,n){
        cin>>arr2[i];
    }
    fore(i,0,n)pq1.push({arr1[i],arr2[i]});

    ll out = 0;
    pq1.pop();
    priority_queue<int,vector<int>,greater<int>> bestResult;
    
    //Estás variables son para manejar las incersiones a la pila de bestResults,
    //si tA>tB significa que puedo meter cosas a la pila no importa que tan malas sean
    //si tB>tA significa que puedo darme el lujo de escoger si llevo o no el proximo valor
    int tA = 1;
    int tB = 0;
    while(pq1.size()>0){
        pair<int,int> currA = pq1.top();
        pq1.pop();
        //cout<<currA.fst<<" "<<" "<<currA.snd.fst<<" "<<currA.snd.snd<<"\n";
        
        if(tA>tB){
            bestResult.push(currA.snd);
            tB++;
        }else{
            if(currA.snd>bestResult.top()){
                bestResult.pop();
                bestResult.push(currA.snd);
            }
            tA++;
        }

        //si lo que estoy evaluando es mejor que el peor puntaje que pude escoger pues me lo llevo
    }

    while(!bestResult.empty()){
        out += bestResult.top();
        bestResult.pop();
    }
        
    cout<<out<<"\n";
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
    solve();
    return 0;
}
