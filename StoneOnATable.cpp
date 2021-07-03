#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    char prev = s[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if(s[i] == prev){
            count++;
        } else{
            prev = s[i];
        }
    }
    cout << count << endl;

    return 0;
}
