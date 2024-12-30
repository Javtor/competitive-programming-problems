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
        cout<<fixed<<setprecision(9);
        double denominador[51];
        double numerador[51];
        denominador[0] = 1.0;
        numerador[0] = 1.0;
        numerador[1] = 4.0;
        denominador[1] = 5.0;
        double students[n];
        fore(i,2,51){
            numerador[i] = (numerador[i-1]*4.0);
            denominador[i] = (denominador[i-1]*5.0);
        }
        fore(i,0,n){
            cin>>students[i];
        }
        double result= 0;
        fore(i,0,n){
            result += (students[i]*numerador[i])/denominador[i];
        }
        result = result*0.2;
        cout<<result<<"\n";

        result = 0;
        fore(i,0,n){
            double t_result = 0;
            int pos = 0;
            fore(j,0,n){
                if(i!=j){
                    t_result += (students[j]*numerador[pos])/denominador[pos];
                    pos++;
                }
            }
            result += t_result*0.2;
        }
        result /= n;
        cout<<result<<"\n";

        return 0;
    }
