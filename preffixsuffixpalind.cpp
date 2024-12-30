#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i, a, b) for (int i = a, almo5t = b; i < almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN                                \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL)

typedef long long int ll;

using namespace std;

vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

int main()
{
    FIN;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string patbase;
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                patbase += s[l];
                l++;r--;
            }
            else
            {
                break;
            }
        }
        if (l == r)
        {
            cout << s << "\n";
        }
        else
        {
            string ns = s.substr(patbase.length(), s.length()-2*patbase.length());
            string rs = ns;
            reverse(all(rs));
            string s1 = ns+"$"+rs;
            string s2 = rs+"$"+ns;
            vector<int> z1 = z_function(s1);
            vector<int> z2 = z_function(s2);
            string pal = "";
            string pal2 = "";

            fore(j,0,ns.length()){
                int i = j+ns.length()+1;
                if(z1[i]==ns.length()-j){
                    pal = ns.substr(0,ns.length()-j);
                    break;
                }
            }
            fore(j,0,ns.length()){
                int i = j+ns.length()+1;
                if(z2[i]==ns.length()-j){
                    pal2 = rs.substr(0,rs.length()-j);
                    break;
                }
            }
            string patbase2 = patbase;
            reverse(all(patbase2));
            if(pal.length()>=pal2.length()){
                cout << patbase << pal << patbase2 << "\n";
            } else{
                cout << patbase << pal2 << patbase2 << "\n";
            }
        }
    }
    return 0;
}
