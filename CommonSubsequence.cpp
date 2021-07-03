#include <iostream>   
#include <algorithm>    
using namespace std;
 
typedef long long ll;
 
int main()
{
// For getting input from input.txt file   
 
        string s1, s2;
 
        cin >> s1;
        cin >> s2;
 
		int n = s1.length();
//		int maxDist = n;
		int maxDist = n/100;
 
		ll memo[2][2*maxDist + 3];
 
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2*maxDist + 3; j++)
            {
                memo[i][j] = 0;
            }
            
        }
		
//		int maxPos = 0;
 
		for (int i = n-1; i >= 0; i--) {
			for (int j = min(maxDist, n-i-1); j >= -maxDist && i + j >= 0; j--) {
				
				int jInt = j+maxDist+1;
 
					if (i == n || j == n || i + j == n) {
						memo[i % 2][jInt] = 0;
					} else if (s1[i] == s2[i + j]) {
						memo[i % 2][jInt] = 1 + memo[(i + 1) % 2][jInt];
					} else {
						memo[i % 2][jInt] = max(memo[i % 2][jInt + 1], memo[(i + 1) % 2][jInt-1]);
					}
 
			}
		}
 
		cout << (memo[0][maxDist+1] >= 0.99*n ? "Long lost brothers D:" : "Not brothers :(") << endl;
    return 0;
}
