#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
    
string d[2];
ll x[2], y[2], s[2], w[2], l[2], vx[2], vy[2];
ll sx[2], sy[2], bx, by;
ll t;

void checkTime(ll testTime) {
    if (testTime < 0 || testTime > t)
        return;
    ll curx[2], cury[2];
    rep(i,0,2) {
        curx[i] = x[i] + vx[i]*testTime;
        cury[i] = y[i] + vy[i]*testTime;
    }
    ll dx = abs(curx[0] - curx[1]);
    ll dy = abs(cury[0] - cury[1]);
    if (2*dx >= sx[0]+sx[1])
        return;
    if (2*dy >= sy[0]+sy[1])
        return;
    cout << "crash" << endl;
    exit(0);
}

int main(){
	    
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    cin >> t;
    for (int i = 0; i < 2; i++) {
        cin >> d[i] >> x[i] >> y[i] >> s[i] >> w[i] >> l[i];
    }
    ll mul = 2 * s[0] * s[1];
    t *= mul;
    rep(i,0,2) {
        x[i] *= mul;
        y[i] *= mul;
        w[i] *= mul;
        l[i] *= mul;
        if (d[i] == "N") {
            vx[i] = 0;
            vy[i] = s[i];
            sx[i] = w[i];
            sy[i] = l[i];
        }
        if (d[i] == "S") {
            vx[i] = 0;
            vy[i] = -s[i];
            sx[i] = w[i];
            sy[i] = l[i];
        }
        if (d[i] == "E") {
            vx[i] = s[i];
            vy[i] = 0;
            sx[i] = l[i];
            sy[i] = w[i];
        }
        if (d[i] == "W") {
            vx[i] = -s[i];
            vy[i] = 0;
            sx[i] = l[i];
            sy[i] = w[i];
        }
    }
    bx = (sx[0] + sx[1])/2;
    by = (sy[0] + sy[1])/2;
    checkTime(0);
    checkTime(t);
    for (int factor = -1; factor <= 1; factor += 2) {
        ll dv = vx[0] - vx[1];
        if (dv == 0) {
            continue;
        }
        ll testTime = (x[1] - x[0] + factor*bx) / dv;
        checkTime(testTime-1);
        checkTime(testTime);
        checkTime(testTime+1);
    }
    for (int factor = -1; factor <= 1; factor += 2) {
        ll dv = vy[0] - vy[1];
        if (dv == 0) {
            continue;
        }
        ll testTime = (y[1] - y[0] + factor*by) / dv;
        checkTime(testTime-1);
        checkTime(testTime);
        checkTime(testTime+1);
    }
    cout << "safe" << endl;
}
