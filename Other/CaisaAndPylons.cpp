#include <iostream>
using namespace std;
int main(){

    int n;
    int min = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int anterior = arr[0];
    int costoActual = 0;
    for (int i = 1; i < n; i++)
    {
        costoActual += anterior-arr[i];
        anterior = arr[i];
        if(costoActual < min){
            min = costoActual;
        }
    }
    
    cout << arr[0]-min << endl;
    
    return 0;
}