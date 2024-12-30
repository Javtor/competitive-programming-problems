#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, l;
    scanf("%d %d",&n,&l);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n); 

    double min = (double)arr[0];U
    
    min = std::max(min, (double)(l-arr[n-1]));

    for (int i = 1; i < n; i++)
    {
        min = std::max(min, ((double)arr[i]-(double)arr[i-1])/2.0 );
    }
    
    printf("%.9f\n",min);
  
    return 0; 
}