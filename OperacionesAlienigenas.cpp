#include <iostream>
using namespace std;
typedef long long int ll;
int main(){

    ll a,b;
    while(scanf("%lld %lld", &a, &b) != -1){
        cout << (a^b) << endl;
    }
    return 0;
}