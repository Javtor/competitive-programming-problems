#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin >> n;
    ll count = 1;
    n--;
    string word, prev;
    cin >> prev;
    while(n--){
        cin >> word;

        if(word != prev){
            count++;
        }

        prev = word;
    }
    cout << count << endl;
    return 0;
}