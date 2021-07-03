#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2*n];
    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            arr[i] = i+1;
            arr[i+n] = i+2;
        } else{
            arr[i] = 2*n + 1 - i;
            arr[i+n] = 2*n - i;;
        }
    }

    if(n%2 == 0)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << arr[0];

        for (int i = 1; i < 2*n; i++)
        {
            cout << " "<< arr[i];
        }
        cout << endl;
        return 0;
    }
}