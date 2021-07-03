#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long arra[n];

    bool negatImpar = false;
    long long  count = 0;
    int ceros = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arra[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(arra[i] < 0){
            negatImpar = !negatImpar;
            count += -1-arra[i];
        } else if(arra[i] > 0){
            count += arra[i]-1;
        } else{
            ceros++;
        }
    }

    if(ceros > 0){
           count += ceros; 
    } else{
        if(negatImpar){
            count += 2;
        }
    }
    
    cout << count << endl;

    return 0;
}