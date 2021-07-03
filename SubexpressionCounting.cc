#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int N = 8010;
 
typedef long long int ll;
 
using namespace std;

int arr[N];
int n;

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

int search(string text, string pattern) 
{ 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
  
    vector<int> Z = z_function(concat); 
    int out = 0;
    
    for (int i = 0; i < l; ++i) 
    { 
        if (Z[i] == SZ(pattern)) out++;
    }
    return out;
} 

string sProcess(string s){
    string out = "";
    bool num = false;
    fore(i,0,s.size()){
        char c = s[i];
        if(num && !isdigit(c)){
            num = 0;out+='n';
        }
        if(c == '+' || c == '*' || c == '/' || c == '-'){
            out+='o';
        }
        else if(isdigit(c)){
            num = 1;
        } else if(isalpha(c)) out+='n';
        else  out+=c;
    }
    if(num)out+='n';
    return out;
}

int main(){
    FIN;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    string s1;
    string s2;
    while(cin>>s1>>s2){
        string alpha = sProcess(s1);
        string beta = sProcess(s2);
        int out =  search( beta, alpha);
        cout<<out<<"\n";
    }

    return 0;
}