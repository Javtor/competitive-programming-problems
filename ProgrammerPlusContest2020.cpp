#include <iostream>
#include <string>

using namespace std;

string func(const string &s)
{
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans += to_string(tolower(s[n - i - 1]) - 'a' + i + 1);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << func(s);
    return 0;
}
