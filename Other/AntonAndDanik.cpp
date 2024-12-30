#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    char c;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if(c == 'A'){
            result++;
        } else{
            result--;
        }
    }

    string ans;
    if(result > 0){
        ans = "Anton";
    } else if(result < 0){
        ans = "Danik";
    } else {
        ans = "Friendship";
    }
    
    cout << ans;

    return 0;
}
