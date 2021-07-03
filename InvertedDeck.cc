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

int main(){
    int n;cin>>n;
    int p[n];
    fore(i,0,n){
        cin>>p[i];
    }

    int s = 0;
    int e = 0;
    bool boom = false;
    fore(i,0,n-1){
        if(p[i]>p[i+1]){
            s = i;
            boom = true;
            break;
        }
    }
    if(boom) e = n-1;
    fore(i,s,n-1){
        if(p[i]<p[i+1]){
            e = i;
            break;
        }
    }
    
    bool search = true;
    int i = s;
    while(i >= 0 && search){
        if(p[i]==p[s]){
            s = i;
        } else
        {
            search = false;
        }      
        i--;
    }

    search = true;
    i = e;
    while(i < n && search){
        if(p[i]==p[s]){
            s = i;
        } else
        {
            search = false;
        }      
        i++;
    }

    reverse(p+s,p+e+1);
 
    bool sorted = true;
    fore(i,1,n){
        sorted = sorted && p[i]>= p[i-1];
    }

    s++;e++;
    if(sorted){
    cout<<s<<" "<<e<<"\n";
    } else{
        cout<<"impossible\n";
    }

    return 0;
}