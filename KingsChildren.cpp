#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI acos(-1)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int n,m;
const int MAXN = 1e3+10;
int a[MAXN][MAXN], sum[MAXN][MAXN];
string s[MAXN];

int getsum(int x0, int y0, int x1, int y1){
    int sumOr = sum[x1][y1];
    int izq = y0-1>=0?sum[x1][y0-1]:0;
    int arr = x0-1>=0?sum[x0-1][y1]:0;
    int esq = x0-1>=0&&y0-1>=0?sum[x0-1][y0-1]:0;
    return sumOr-izq-arr+esq;
}

void llenar(int x0, int y0, int x1, int y1){
    fore(i,x0,x1+1){
        char var='1';
        fore(j,y0,y1+1){
            if(s[i][j] != 'a' && s[i][j] != 'A' && s[i][j] != '.'){
                var = s[i][j];break;
            }
        }
        if(var == '1') continue;
        var+=32;
        fore(j,y0,y1+1){
            if(s[i][j] == '.') s[i][j] = var;
            else var = s[i][j]+32;
        }
    }
    int ind = -1;
    fore(i,x0,x1+1){
        if(s[i][y0] != '.'){ ind=i; break;}
    }
    fore(i,x0,x1+1){
        if(s[i][y0] != '.'){ ind=i; continue;}
        fore(j,y0,y1+1){
            s[i][j] = (s[ind][j]<'a'?s[ind][j]+32:s[ind][j]);
        }
    }
}

int main() {FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    #define endl '\n'
    #endif
    cin>>n>>m; memset(a,0,sizeof(a));
    int si,sj;
    fore(i,0,n){
        cin>>s[i];
        fore(j,0,m){
            if(s[i][j] == 'A'){
                si=i; sj=j;
            }else if(s[i][j] != '.' && s[i][j] != 'A'){
                a[i][j] = 1;
            }
        }
    }

    sum[0][0] = a[0][0];
    fore(i,1,n) sum[i][0] = sum[i-1][0]+a[i][0];
    fore(i,1,m) sum[0][i] = sum[0][i-1]+a[0][i];
    fore(i,1,n){
        fore(j,1,m){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
        }
    }

    vector<int> v(4); int ans = 0;
    fore(izq,0,m){
        if(sj-izq>=0){
            fore(der,0,m){
                if(sj+der<m && getsum(si,sj-izq,si,sj+der) == 0){
                    //Arriba
                    int l =0, r = si, up = 0;
                    while(l<=r){
                        int m = (l+r)/2;
                        if(getsum(si-m,sj-izq,si,sj+der)==0){up=max(up,m); l = m+1;}
                        else r = m-1;
                    }
                    //Abajo
                    l =0, r = n-si-1; int dw = 0;
                    while(l<=r){
                        int m = (l+r)/2;
                        if(getsum(si,sj-izq,si+m,sj+der)==0){dw=max(dw,m); l = m+1;}
                        else r = m-1;
                    }
                    int area = ((sj+der)-(sj-izq)+1)*((si+dw)-(si-up)+1);
                    if(area>ans){
                        ans = area;
                        v[0]=up; v[1]=dw; v[2]=izq; v[3]=der;
                    }
                }
            }
        }
    }

    fore(up,0,n){
        if(si-up>=0){
            fore(dw,0,n){
                if(si+dw<n && getsum(si-up,sj,si+dw,sj) == 0){
                    //Izquierda
                    int l =0, r = sj, izq = 0;
                    while(l<=r){
                        int m = (l+r)/2;
                        int gs = getsum(si-up,sj-m,si+dw,sj);
                        if(gs==0){izq=max(izq,m); l = m+1;}
                        else r = m-1;
                    }
                    //Derecha
                    l =0, r = m-sj-1; int der = 0;
                    while(l<=r){
                        int m = (l+r)/2;
                        if(getsum(si-up,sj,si+dw,sj+m)==0){der=max(der,m); l = m+1;}
                        else r = m-1;
                    }
                    int area = ((sj+der)-(sj-izq)+1)*((si+dw)-(si-up)+1);
                    if(area>ans){
                        ans = area;
                        v[0]=up; v[1]=dw; v[2]=izq; v[3]=der;
                        cout<<si-v[0]<<" "<<sj-v[2]<<" "<<si+v[1]<<" "<<sj+v[3]<<"\n";
                    }
                }
            }
        }
    }

    fore(j,sj-v[2],sj+v[3]+1){
        fore(i,si-v[0],si+v[1]+1){
            if(s[i][j] != 'A')
                s[i][j] = 'a';
        }
    }

    if(si-v[0] > 0) llenar(0,0,si-v[0]-1,m-1);
    if(si+v[1] < n-1) llenar(si+v[1]+1,0,n-1,m-1);
    if(sj-v[2] > 0) llenar(si-v[0],0,n-1,sj-v[2]-1);
    if(sj+v[3] < m-1) llenar(si-v[0],sj+v[3]+1,n-1,m-1);
    fore(i,0,n) cout<<s[i]<<"\n";
    return 0;
}

