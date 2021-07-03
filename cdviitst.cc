#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef map<int, int> ii;

int getTime( const string& buf ){
	int mon, day, hr, min;
	sscanf( buf.c_str(), "%d:%d:%d:%d", &mon, &day, &hr, &min );
	return day * 24 * 60 + hr * 60 + min;
}

vector<int> cost(24);
double Price( ii& n ){
	int ans = 0;
	for(auto it = n.begin(); it != n.end(); it++ ){
		if( it->second >= 0 ){
			if( it == n.begin() ) continue;
			auto it2 = it;
			it2--;
			if( it2->second < 0 ){
				int prev = -it2->second - 1;
				int km = it->second - prev;
				int pr = cost[(it2->first/60)%24];
				ans += 100 + abs(km * pr);
			}
		}
	}
	return ans? (double)(ans+200)/100.0 : 0;
}

int main(){
        FIN;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
	cout.precision(2);
	cout << fixed;
	int t;cin >> t;
	while(t--){
		for( int i=0; i<24; ++i ) cin >> cost[i];
		
        cin.ignore();
		map<string, ii> m;
        
		string line;
		while( getline(cin, line) && !line.empty() ){
			istringstream in(line);
			string plate,time,tp;
			int x;
			in>>plate>>time>>tp>>x;
			ii& n = m[plate];
			int tm = getTime(time);
			n[tm] = ( tp[1] == 'n' ? -x - 1 : x );
		}
		for( auto el : m ){
			double price = Price( el.second );
			if( price)
			    cout << el.first << " $" << price << endl;
		}
		if(t) cout << endl;
	}
}