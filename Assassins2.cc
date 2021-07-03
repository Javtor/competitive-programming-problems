#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
	int N, M;
	cin >> N >> M;
	vector<double> prob(1 << N, 0), nprob;
	prob[0] = 1;
	rep(i,0,M) {
		int a, b;
		double p;
		cin >> a >> b >> p;
		--a, --b;
		nprob.assign(1 << N, 0);
		rep(bi,0,(1 << N)) {
			if (bi & ((1 << a) | (1 << b))) {
				// either is dead
				nprob[bi] += prob[bi];
			} else {
				nprob[bi | (1 << b)] += prob[bi] * p;
				nprob[bi] += prob[bi] * (1 - p);
			}
		}
		nprob.swap(prob);
	}

	vector<double> dead(N);
	rep(bi,0,(1 << N)) rep(i,0,N) {
		if (bi & (1 << i))
			dead[i] += prob[bi];
	}
	rep(i,0,N) cout << setprecision(10) << fixed << 1 - dead[i] << endl;
}
