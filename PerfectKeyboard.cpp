#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, alm = b; i < alm; ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool juntos[26][26];
        bool yastan[26];
        memset(juntos, 0, sizeof(juntos));
        memset(yastan, 0, sizeof(yastan));
        vector<int> graph[26];
        string s;
        cin >> s;
        fore(i, 1, s.size())
        {
            int ant = s[i - 1] - 'a';
            int este = s[i] - 'a';
            if (!juntos[ant][este])
            {
                graph[ant].pb(este);
                graph[este].pb(ant);
                juntos[ant][este] = true;
                juntos[este][ant] = true;
            }
        }
        int grado1 = 0;
        int grado2 = 0;
        int indG1 = -1;
        fore(i, 0, 26)
        {
            if (graph[i].size() == 1)
            {
                grado1++;
                indG1 = i;
            }
            else if (graph[i].size() == 2 || graph[i].size() == 0)
                grado2++;
        }
        if(s.size()==1){
            string keyboard = s;
            yastan[s[0]-'a']=true;
            
            fore(i,0,26){
                if(!yastan[i]){
                    keyboard+=(char)(i+'a');
                }
            }

            cout << "YES"
                 << "\n";
                 cout<<keyboard<<"\n";
        }
        else if (grado1 > 0 && grado1 + grado2 == 26)
        {
            cout << "YES"
                 << "\n";
            string keyboard = "";
            bool ag=true;
            int ind = indG1;
            while(ag){
                keyboard+=(char)(ind+'a');
                yastan[ind]=true;
                ag=false;
                int nextBueno = ind;
                fore(i,0,graph[ind].size()){
                    int nextIn = graph[ind][i];
                    if(!yastan[nextIn]){
                        ag=true;
                        nextBueno = nextIn;
                    }
                }
                ind = nextBueno;
            }
            fore(i,0,26){
                if(!yastan[i]){
                    keyboard+=(char)(i+'a');
                }
            }
            cout<<keyboard<<"\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
    return 0;
}